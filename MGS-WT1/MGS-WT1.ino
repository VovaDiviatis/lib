#include <Wire.h>
#include "mcp3021.h"
byte ADDR = 0b001; // 0x49
// (также попробуйте просканировать адрес: https://github.com/MAKblC/Codes/tree/master/I2C%20scanner)
// 0x48 (000)...0x4F(111)

MCP3021 mcp3021;

// калибровочные значения с АЦП
const float air_value = 561.0;
const float water_value = 293.0;
const float moisture_0 = 0.0;
const float moisture_100 = 100.0;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация I2C интерфейса
  Wire.begin();
  mcp3021.begin(ADDR);
}

void loop() {
  // Измерение
  float adc0 = mcp3021.readADC();
  float h = map(adc0, air_value, water_value, moisture_0, moisture_100);
  // Вывод измеренных значений в терминал
  Serial.println("Water level = " + String(h, 1) + " %");
  delay(250);
}

