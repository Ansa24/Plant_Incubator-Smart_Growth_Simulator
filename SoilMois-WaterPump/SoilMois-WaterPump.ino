//
//#define BLYNK_PRINT Serial     //defines the object that is used for printing
//
//#include <BlynkSimpleEsp8266.h>    //to use Blynk app functionalities
//#include <ESP8266WiFi.h>     //to connect HDK to WiFi

int sensor_pinsm = A0;
int output_valuesm ;
int moisturevalue = 350;
int wateringtime= 10000;
char auth[] ="3c87b90093674378a42642924d65b4a0";  //define a variable to store your authorization token
  
 /*define variables to store WiFi credentials*/
 
  char ssid[] = "Avi";
  char pass[] = "12346789";    //if password blank then leave just double quotes


void setup() 
{
//sm
Serial.begin(115200);
//Blynk.begin(auth, ssid, pass);     //connects to network and establishes the connection with Blynk server
//pinMode(V2, INPUT);
Serial.println("Connected to \nNetwork Name:");
Serial.println(ssid);
Serial.println("\nNetwork Password:");
Serial.println(pass);

Serial.println("\nReading From the Sensor ...");
delay(2000);
//smend
pinMode(5, OUTPUT);

}

//BLYNK_CONNECTED()
//{
//  Blynk.syncVirtual(V2);
//}
//
//BLYNK_WRITE(V2)
//{
//  int buttonState=param.asInt();
//}

void loop() {

//sm
  // Blynk.run();
   output_valuesm= analogRead(sensor_pinsm);
     Serial.print("Mositure : ");
  
     Serial.print(output_valuesm);
 
     Serial.println("%");


if(output_valuesm>moisturevalue)
   { Serial.print("Current State of Water Pump: ON, \n Buzzer: ON\n\n");
      
           digitalWrite(5,HIGH);
           delay(wateringtime);
       
   }
   if(output_valuesm<moisturevalue)
   { Serial.print("Current State of Water Pump: OFF, , \n Buzzer: OFF\n\n");
      
           digitalWrite(5,LOW);
           delay(wateringtime);
   }

}
