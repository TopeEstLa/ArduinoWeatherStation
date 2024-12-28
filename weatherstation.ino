#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);

DHT dht_11(2, DHT11);
DHT dht_22(4, DHT22);

float temp;
float hum;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht_11.begin();
  dht_22.begin();
}

void loop() {
  hum = dht_22.readHumidity(); //Only get humidity from the DHT 22

  float temp_11 = dht_11.readTemperature();
  float temp_22 = dht_22.readTemperature();

  temp = (temp_11 + temp_22) / 2; //take the average between DHT11 & DHT22 

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.print(temp);
  lcd.print(" c");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print(" %");

  delay(2000);
}
