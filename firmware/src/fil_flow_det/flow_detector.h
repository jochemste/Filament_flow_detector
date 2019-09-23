#ifndef FLOW_DETECTOR_H
#define FLOW_DETECTOR_H


#include "enums.h"
#include "error_handler.h"
#include "definitions.h"
#ifdef ENCODER_ENABLED
  #include "encoder.h"
#endif ENCODER_ENABLED
#include <Arduino.h>

class Flow_detector{
 public:
  Flow_detector(bool &flow_error);
  ~Flow_detector();

  void run();
  bool check();
  
 private:
  bool* no_flow;
#ifdef ENCODER_ENABLED
  Encoder* encoder;
  encoder_state current_enc_state;
  encoder_state previous_enc_state;
  bool check_encoder();
#endif ENCODER_ENABLED
  unsigned long time_last_state_change;
};


#endif FLOW_DETECTOR_H
