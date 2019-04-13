//You will need the adafruit MCP9808 library which is available at https://github.com/adafruit/Adafruit_MCP9808_Library/archive/master.zip

#include <Wire.h>
#include "Adafruit_MCP9808.h"

// Create the MCP9808 temperature sensor object
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

void setup() {
  Serial.begin(9600);
  
  if (!tempsensor.begin()) 
  {
    Serial.println("Couldn't find MCP9808!");
    while (1);
  }
}

void loop() {
  // Read and print out the temperature, then convert to *F
  float c = tempsensor.readTempC();
  float f = c * 9.0 / 5.0 + 32;
  Serial.print("Temp: "); 
  Serial.print(c); 
  Serial.print(" C\t"); 
  Serial.print(f); 
  Serial.println(" F");
  delay(250);
  
  tempsensor.shutdown_wake(1);
  delay(2000);
  tempsensor.shutdown_wake(0);
  
   
}


