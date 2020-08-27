#include "DHT.h"
#define dataPin 2 
#define DHTTYPE DHT11   // DHT 11 

// Initialize DHT sensor for normal 16mhz Arduino
DHT mDHT(dataPin, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  mDHT.begin();
}

void loop() {
  delay(1000);

  int rounded_humid = int(mDHT.readHumidity()+0.5);
  int rounded_temp = int(mDHT.readTemperature()+0.5);
  
  if (isnan(rounded_humid) || isnan(rounded_temp)) {
    return;
  }

  Serial.print(String(rounded_temp)+",");
  Serial.println(rounded_humid);
  
}
