#include <LiquidCrystal.h>

#include <Adafruit_Sensor.h>

#include <DHT.h> // From https://github.com/adafruit/DHT-sensor-library
#include <DHT_U.h>

#define dht_dpin 9 // Pin for dht sensor data 
#define dht_type DHT11 //Dht sensor type (DHT11, DHT21, DHT22)
DHT dht (dht_dpin, dht_type);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){

dht.begin();
lcd.begin(16, 2);
//Serial.begin(57600); 
}

void loop(){

float temp = dht.readTemperature(false);
delay(6000);
float hum = dht.readHumidity();

if (isnan(temp)) {temp = 0;} // If sensor return NaN, values are 0
if (isnan(hum)) {hum=0;}

lcd.print("TEMP     ");
lcd.print(temp);
lcd.print("C "); 
lcd.setCursor(0,1);
lcd.print("HUMIDITY ");
lcd.print(hum);
lcd.print("%  "); 
delay(6000);
}
