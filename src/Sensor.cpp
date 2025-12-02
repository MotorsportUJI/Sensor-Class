#include "Sensor.h"
#include <math.h>
#define Vcc 5.0
#define R 1000.0 // Resistencia en ohmios
#define Beta 4024.033775
#define Tref 298.15 // Temperatura de referencia en Kelvin
#define Rref 2796.0 // Resistencia de referencia en ohmios


Sensor::Sensor(uint8_t pin, long minValSalida, long maxValSalida, long minValEntrada, long maxValEntrada) {
  this->pin = pin;
  this->minValSalida = minValSalida;
  this->maxValSalida = maxValSalida;
  this->minValEntrada = minValEntrada;
  this->maxValEntrada = maxValEntrada;
}

void Sensor::beginInput() {
  pinMode(pin, INPUT);
}

void Sensor::beginOutput() {
  pinMode(pin, OUTPUT);
}


/*Ejemplo de uso: 
  Sensor temperatura = Sensor(A1, 0, 100);
  uint8_t temp = temperatura.readTemperature();

  Si es un sensor que mide valores altos, usar de forma:
  Sensor amortiguador = Sensor(A0, 0, 200, 0, 4000);    En este ejemplo, el sensor esta puesto para que lea datos de 0 a 4000 y cuando hagamos un read<uint16_t>(), nos devolvera un valor mapeado de 0 a 200.
  uint16_t presion = amortiguador.read<uint16_t>();
*/
uint8_t Sensor::readTemperature() {

  float Vint = (Vcc / 1023.0) * analogRead(pin);
  float R_termistor = (Vint * R) / (Vcc - Vint);
  float T_termistor_K = Beta / (log(R_termistor / Rref) + (Beta / Tref));
  float T_termistor_C = T_termistor_K - 273.15;

  return round(T_termistor_C);
}