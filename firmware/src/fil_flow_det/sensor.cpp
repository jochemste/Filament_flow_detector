#include "sensor.h"

void Sensor::init_input_pin(int pin, int mode){
  if(mode == input)
    pinMode(pin, INPUT);
  else
    pinMode(pin, OUTPUT);
}
