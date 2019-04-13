//You need to download 2 libraries and install them using the library manager.

//http://download.milesburton.com/Arduino/MaximTemperature/DallasTemperature_372Beta.zip
//http://www.pjrc.com/teensy/arduino_libraries/OneWire.zip

#include <OneWire.h>
#include <DallasTemperature.h>

//the pin you connect the ds18b20 to
#define DS18B20 2

OneWire ourWire(DS18B20);
DallasTemperature sensors(&ourWire);

void setup()
{
Serial.begin(9600);
delay(1000);
//start reading
sensors.begin();
}

void loop()
{
//read temperature and output via serial
sensors.requestTemperatures();
Serial.print(sensors.getTempCByIndex(0));
Serial.println(” degrees C”);
}


