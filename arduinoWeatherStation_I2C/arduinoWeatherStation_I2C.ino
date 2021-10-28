#include <LiquidCrystal_I2C.h>  // From https://github.com/johnrickman/LiquidCrystal_I2C

#include <Adafruit_Sensor.h>

#include <DHT.h>  // From https://github.com/adafruit/DHT-sensor-library
#include <DHT_U.h>

#define dht_dpin 12 // Pin for dht sensor data 
#define dht_type DHT22 // Dht sensor type (DHT11, DHT21, DHT22)
DHT dht (dht_dpin, dht_type);

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initializes the lcd with address, columns and rows

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float temp = dht.readTemperature();
  delay(700);
  float hum = dht.readHumidity();

  if (isnan(temp)) temp = 0; // If sensor return NaN, values are 0
  if (isnan(hum)) hum=0;
  
  lcd.setCursor(0, 0);
  lcd.print("TEMP     ");
  lcd.print(temp);
  lcd.print("C"); 
  lcd.setCursor(0,1);
  lcd.print("HUMIDITY ");
  lcd.print(hum);
  lcd.print("%"); 
  delay(1000);
}
