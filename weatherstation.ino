#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);
DHT dht(2, DHT11);
DHT dht2(4, DHT22);

float temp;
float hum;
float temp2;
float hum2;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();
  dht2.begin();
}

void loop() {
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  hum2 = dht2.readHumidity();
  temp2 = dht2.readTemperature();

  Serial.print("Hum:");
  Serial.print(hum);
  Serial.print("Temp: ");
  Serial.print(temp);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(temp);
  lcd.setCursor(0, 2);
  lcd.print("Temp2: ");
  lcd.print(temp2);
  lcd.setCursor(0, 3);
  lcd.print("Hum2: ");
  lcd.print(hum2);

  delay(2000);
}
