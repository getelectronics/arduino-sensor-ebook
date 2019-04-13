//You will need the DHT11 library from the https://github.com/getmicros/Arduino-Libraries/blob/master/dht11.zip. 
//Download, extract and import this to your Arduino libraries folder location. This is a simple example which outputs the humidity and temperature, place your fingers on the DHT11 and you will see the readings fluctuate 
#include <dht11.h>

dht11 DHT;
//Pin 4 of Arduino to Data of DHT11
#define DHT11_PIN 4

void setup()
{
Serial.begin(9600);
int check;
Serial.print(“DHT11 STATUS – \t”);
check = DHT.read(DHT11_PIN);
//check status
switch (check)
{
case DHTLIB_OK:
Serial.print(“OK\n”);
break;
case DHTLIB_ERROR_CHECKSUM:
Serial.print(“Checksum error\n”);
break;
case DHTLIB_ERROR_TIMEOUT:
Serial.print(“Timeout error\n”);
break;
default:
Serial.print(“Unknown error\n”);
break;
}
}

void loop()
{

//humidity and temperature output
Serial.print(“Humidity is “);
Serial.print(DHT.humidity,1);
Serial.print(“\n”);
Serial.println(“Temperature is “);
Serial.println(DHT.temperature,1);

delay(1000);
}

