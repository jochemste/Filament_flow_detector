#ifndef SENSOR_H
#define SENSOR_H

#include "enums.h"
#include <Arduino.h>

class Sensor{
 public:
  Sensor(): initialised(false){}
  ~Sensor(){}

  void toggle_initialised();
  bool get_initialised_state();
  void init_input_pin(int pin, int input);

 private:
  bool initialised;
};

#endif SENSOR_H
