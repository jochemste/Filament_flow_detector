#ifndef FLOW_DETECTOR_H
#define FLOW_DETECTOR_H

#include "enums.h"
#include "error_handler.h"
#include "definitions.h"
#include "Configuration.h"
//#ifdef ENCODER_ENABLED
  #include "encoder.h"
//#endif ENCODER_ENABLED
#include <Arduino.h>

class Flow_detector{
 public:
  Flow_detector(bool &flow_error);
  ~Flow_detector();

  void run(); /// Run the flow detector
  bool check(); /// Check if there is a flow error
  //#ifdef TWO_HEADS_ENABLED
  bool check_2();
  //#endif TWO_HEADS_ENABLED
  
  bool get_error();
  //#ifdef TWO_HEADS_ENABLED
  bool get_error_2();
  //#endif TWO_HEADS_ENABLED
  
 private:
  bool* no_flow;
  bool no_flow_1;
  //#ifdef TWO_HEADS_ENABLED
  bool no_flow_2;
  //#endif TWO_HEADS_ENABLED
  //#ifdef ENCODER_ENABLED
  Encoder* encoder;
  encoder_state current_enc_state;
  encoder_state previous_enc_state;

  //  #ifdef TWO_HEADS_ENABLED
    Encoder* encoder_2;
    encoder_state current_enc_state_2;
    encoder_state previous_enc_state_2;
  //  #endif TWO_HEADS_ENABLED

  bool check_encoder();
  //  #ifdef TWO_HEADS_ENABLED
    bool check_encoder_2();
    unsigned long time_last_state_change_2;
  //  #endif TWO_HEADS_ENABLED
  //#endif ENCODER_ENABLED
  unsigned long time_last_state_change;
  
};


#endif FLOW_DETECTOR_H
