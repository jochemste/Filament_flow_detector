#ifndef SENSOR_H
#define SENSOR_H

#include "enums.h"
#include <Arduino.h>

class Sensor{
 public:
  Sensor(){}
  ~Sensor(){}

  void init_input_pin(int pin, int input);
 private:
  
};

#endif SENSOR_H
