#include "EspMQTTClient.h"                  
#include <Stepper.h>
Stepper stepper_1(2048,D12,D14,D13,D15);
EspMQTTClient client(
  "**",                   // Wifi name
  "**",                   // Wifi pass
  "broker.mqttdashboard.com",     
  "clientId-A07BYIcbJX",  // Publish name - Client ID    
  1883);
void onConnectionEstablished(){
  client.subscribe("clientId",[](const String&payload){           
    Serial.println(payload);                                        
    if(payload=="İleri"){                                        
      stepper_1.step(350);
      client.publish("clientId","Motor ileri yönde dönüyor.");       
      delay(2000);                                                   
    }if(payload=="Geri"){                                            
      stepper_1.step((-350));                                       
      client.publish("clientId","Motor geri yönde dönüyor.");
      delay(2000);
    }if(payload.toInt()>=1){                                    
      stepper_1.setSpeed(payload.toInt());                       
    }
  });}
void setup() {
  Serial.begin(115200);
  stepper_1.setSpeed(10);
  client.enableDebuggingMessages();
  client.enableHTTPWebUpdater();
  client.enableOTA();
}
void loop() {
  client.loop();
}