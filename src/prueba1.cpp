#include "Sensor.h"

Sensor amort1 = Sensor(A0, 0, 254, 0, 4000); // Configuración del sensor de presion de amortiguador
Sensor temp_Motor = Sensor(A1, 0, 100); // Configuración del sensor de temperatura

void setup() {
  Serial.begin(9600);
  amort1.beginInput();
  temp_Motor.beginInput();
}

void loop() {
  uint16_t amort1_val = amort1.read<uint16_t>();
  Serial.print("Presion amortiguador1: ");
  Serial.print(amort1_val);
  Serial.println(" psi");

  uint8_t temperatura = temp_Motor.readTemperature();
  Serial.print("Temperatura del motor: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  delay(1000); // Esperar 1 segundo antes de la siguiente lectura
  
}