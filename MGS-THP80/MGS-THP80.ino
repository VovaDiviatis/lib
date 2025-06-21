#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
Adafruit_BME280 bme280;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация датчика
  bool bme_status = bme280.begin(); // (также попробуйте просканировать адрес: https://github.com/MAKblC/Codes/tree/master/I2C%20scanner)
  if (!bme_status)
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
}

void loop() {
  // Измерение
  float t = bme280.readTemperature();
  float h = bme280.readHumidity();
  float p = bme280.readPressure() / 100.0F;
  // Вывод измеренных значений в терминал
  Serial.println("Air temperature = " + String(t, 1) + " *C");
  Serial.println("Air humidity = " + String(h, 1) + " %");
  Serial.println("Air pressure = " + String(p, 1) + " hPa"); // 1 mmHg = 1 hPa / 1.33
  delay(250);
}
