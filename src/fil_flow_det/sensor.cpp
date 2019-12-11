#include "sensor.h"

void Sensor::init_input_pin(int pin, int mode){
  if(mode == input)
    pinMode(pin, INPUT);
  else
    pinMode(pin, OUTPUT);
}

void Sensor::toggle_initialised(){
  if(initialised)
    initialised = false;
  else
    initialised = true;
}

bool Sensor::get_initialised_state(){
  return initialised;
}
