#include "DHT.h"

DHT dht(8, DHT11);
int Fan=11;
int blue_LED=5;
int red_LED=6;

void setup() {
  dht.begin();
  pinMode(Fan, OUTPUT);
  pinMode(blue_LED, OUTPUT);
  pinMode(red_LED, OUTPUT);
}

void loop() {
  float hum=dht.readHumidity();
  float temp=dht.readTemperature();
  if (temp > 35){ 
    analogWrite(Fan,255); 
  }
  else if (temp <= 35) { 
    analogWrite(Fan, 0); 
  }

  if (hum > 0.7 || hum < 0.6){  
    digitalWrite(blue_LED, LOW); 
    digitalWrite(red_LED, HIGH); 
  }
  else if (hum >= 0.6 && hum <= 0.7) { 
    digitalWrite(blue_LED, HIGH);
    digitalWrite(red_LED, LOW); 
  }
}
