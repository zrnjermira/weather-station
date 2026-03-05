#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;

void setup() {
  Serial.begin(9600);

  if (!bme.begin(0x76)) {
    Serial.println("Sensor nicht gefunden!");
    while (1);
  }
}

void loop() {

  Serial.print("Temp. ");
  Serial.print(bme.readTemperature(), 1);
  Serial.print(" °C, Hum. ");
  Serial.print(bme.readHumidity(), 0);
  Serial.print("%, Druck. ");
  Serial.print(bme.readPressure() / 100.0F, 0);
  Serial.println("hPa");

  delay(2000);
}