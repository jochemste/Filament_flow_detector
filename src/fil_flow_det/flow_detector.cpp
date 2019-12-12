#include "flow_detector.h"

#ifdef ENCODER_ENABLED
int Encoder::nr_encoders_ = 0;
#endif ENCODER_ENABLED

Flow_detector::Flow_detector(bool &flow_error){
  no_flow = &flow_error;
  *no_flow = false;
#ifdef ENCODER_ENABLED
  encoder = new Encoder();
  encoder->init();
  #ifdef TWO_HEADS_ENABLED
    encoder_2 = new Encoder();
    encoder_2->init();
  #endif TWO_HEADS_ENABLED
#endif ENCODER_ENABLED
}

///@brief Destructor
Flow_detector::~Flow_detector(){
#ifdef ENCODER_ENABLED
  delete encoder;
  #ifdef TWO_HEADS_ENABLED
    delete encoder_2;
  #endif TWO_HEADS_ENABLED
#endif ENCODER_ENABLED
}

/** Main function of the Flow detector to check the encoder state and set
 * a boolean pointer for the fil_flow_det to check for errors. 
 */
void Flow_detector::run(){
  *no_flow = false;
  no_flow_1 = check();
  if(no_flow_1){
    *no_flow = no_flow_1;
  }
  #ifdef TWO_HEADS_ENABLED
  no_flow_2 = check_2();
  if(no_flow_2){
    *no_flow = no_flow_2;
  }
  #endif TWO_HEADS_ENABLED
}

///@brief Checks the encoder state. Returns true for an error and false for flow detected.
bool Flow_detector::check(){
  bool flow_error = false;
#ifdef ENCODER_ENABLED
    flow_error = check_encoder();
#endif ENCODER_ENABLED
    return flow_error;
}

#ifdef TWO_HEADS_ENABLED
bool Flow_detector::check_2(){
  bool flow_error = false;
#ifdef ENCODER_ENABLED
  flow_error = check_encoder();
#endif ENCODER_ENABLED
  return flow_error;
}
#endif TWO_HEADS_ENABLED

bool Flow_detector::get_error(){
  return no_flow_1;
}
 
#ifdef TWO_HEADS_ENABLED
bool Flow_detector::get_error_2(){
  return no_flow_2;
}
#endif TWO_HEADS_ENABLED

#ifdef ENCODER_ENABLED
///@brief Check the encoder
bool Flow_detector::check_encoder(){
  // Allow the encoder to check the current state.
  encoder->update_state();
  // Receive the current state from the encoder.
  previous_enc_state = current_enc_state;
  current_enc_state = encoder->get_state();
  // If the current state differs from the previous one, the encoder is turning.
  if(previous_enc_state != current_enc_state){
    time_last_state_change = millis();
    return false;
  } else {
    if((unsigned long)(millis()-time_last_state_change) >= MAX_INTERVAL){
      return true;
    }
  }
  return false;
}

#ifdef TWO_HEADS_ENABLED
///@brief Check the encoder
bool Flow_detector::check_encoder_2(){
  // Allow the encoder to check the current state.
  encoder_2->update_state();
  // Receive the current state from the encoder.
  previous_enc_state_2 = current_enc_state_2;
  current_enc_state_2 = encoder_2->get_state();
  // If the current state differs from the previous one, the encoder is turning.
  if(previous_enc_state_2 != current_enc_state_2){
    time_last_state_change_2 = millis();
    return false;
  } else {
    if((unsigned long)(millis()-time_last_state_change_2) >= MAX_INTERVAL){
      return true;
    }
  }
  return false;
}
#endif TWO_HEADS_ENABLED
#endif ENCODER_ENABLED
