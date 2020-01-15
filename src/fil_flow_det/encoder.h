#ifndef ENCODER_H
#define ENCODER_H

#include "enums.h"
#include "pins.h"
#include "error_handler.h"
#include "sensor.h"
#include "Configuration.h"
#include <Arduino.h>

class Encoder: public Sensor{

 public:
  Encoder();
  ~Encoder();

  void init();

  void update_state();
  encoder_state get_state();

 private:
  bool turning_;
  int pin_a;
  int pin_b;
  int pin_c;
  encoder_state current_state;
  enc_pin_state current_pin_state;
  enc_pin_state previous_pin_state;

  enc_pin_state read_pins();

  static int nr_encoders_;
};

#endif ENCODER_H
