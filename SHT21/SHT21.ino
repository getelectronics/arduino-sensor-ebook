//I used the following library -  https://github.com/elechouse/SHT21_Arduino

#include <Wire.h>
#include <SHT2x.h>


void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Humidity: ");
  Serial.println(SHT2x.GetHumidity());
  Serial.print("Temperature(C): ");
  Serial.println(SHT2x.GetTemperature());
  Serial.println();
  delay(1000);
}


