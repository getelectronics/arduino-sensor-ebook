//We use the Adafruit TS2561 library - this is a cut down version of the default - https://github.com/adafruit/Adafruit_TSL2561

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

   
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);


void configureSensor(void)
{
  tsl.enableAutoRange(true);            /* Auto-gain ... switches automatically between 1x and 16x */
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
}


void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Light Sensor Test"); 
  Serial.println("");
  
  /* Initialise the sensor */
  if(!tsl.begin())
  {
    Serial.print("no TSL2561 detected!");
    while(1);
  }
  
  configureSensor();
  
}


void loop(void) 
{  
  /* Get a new sensor event */ 
  sensors_event_t event;
  tsl.getEvent(&event);
 
  /* Display the results (light is measured in lux) */
  if (event.light)
  {
    Serial.print(event.light); 
    Serial.println(" lux");
  }
  else
  {
    Serial.println("Sensor overload");
  }
  delay(500);
}


