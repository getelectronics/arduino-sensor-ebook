//The good folks at Adafruit have done the hard work and produced a library for this device - https://github.com/adafruit/Adafruit_HDC1000_Library  .

#include <Wire.h>
#include "Adafruit_HDC1000.h"


Adafruit_HDC1000 hdc = Adafruit_HDC1000();

void setup() 
{
  Serial.begin(9600);
  Serial.println("HDC100x test");

  if (!hdc.begin()) 
  {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
}


void loop() 
{
  Serial.print("Temp: "); Serial.print(hdc.readTemperature());
  Serial.print("\t\tHum: "); Serial.println(hdc.readHumidity());
  delay(500);
}


