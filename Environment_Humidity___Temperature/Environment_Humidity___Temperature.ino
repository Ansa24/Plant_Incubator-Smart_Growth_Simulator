#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int tlimit= 30;
int hlimit=70;
int heatingtime= 1000;


void setup() {

Serial.begin(115200);
Serial.println("DHT11 Output!");
dht.begin();
  // attaches the servo on GIO2 to the servo object 
  pinMode(5, OUTPUT);
}


void loop() {
  
    float h = dht.readHumidity();

  float t = dht.readTemperature();
   if(isnan(t) || isnan(h))
   {
      Serial.println("Failed to read DHT11");
    }
   else
   {

    Serial.print("Humidity: ");

    Serial.print(h);

    Serial.print(" %\t");

    Serial.print("Temperature: ");

    Serial.print(t);

    Serial.println(" *C");



  }

if(h>=hlimit && t<=tlimit)
   { Serial.print("Current State of Bulb: ON\n\n");
      
           digitalWrite(5,HIGH);
           delay(heatingtime);
       
   }
   if(h<hlimit || t>tlimit)
   { Serial.print("Current State of of Bulb: OFF\n\n");
      
           digitalWrite(5,LOW);
           delay(heatingtime);
   }

}

