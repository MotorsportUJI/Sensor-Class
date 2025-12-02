#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
private:
  uint8_t pin;
  long minValSalida;
  long maxValSalida;
  long minValEntrada;
  long maxValEntrada;
  

public:
  Sensor(uint8_t pin, long minValSalida, long maxValSalida, long minValEntrada=0, long maxValEntrada=1023);
  void beginInput();
  void beginOutput();
  uint8_t readTemperature();

  /*Ejemplo de uso: 
  uint16_t valor = sensor.read<uint16_t>();
  */
  template <typename T>
  T read() {
    int valor = analogRead(pin);
    valor = map(valor, minValEntrada, maxValEntrada, minValSalida, maxValSalida);
    return static_cast<T>(valor);
  }
  /*Ejemplo de uso: 
  uint8_t valor = sensor.readRaw<uint8_t>();
  */
  template <typename T>
  T readRaw() {
    int valor = analogRead(pin);
    return static_cast<T>(valor);
  }

};

#endif