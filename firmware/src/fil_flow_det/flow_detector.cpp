#include "flow_detector.h"

Flow_detector::Flow_detector(bool &flow_error){
  no_flow = &flow_error;
  *no_flow = false;
#ifdef ENCODER_ENABLED
  encoder = new Encoder();
  encoder->init();
#endif ENCODER_ENABLED
}

Flow_detector::~Flow_detector(){
#ifdef ENCODER_ENABLED
  delete encoder;
#endif ENCODER_ENABLED
}

/** Main function of the Flow detector to check the encoder state and set
 * a boolean pointer for the fil_flow_det to check for errors. 
 */
void Flow_detector::run(){
  *no_flow = check();
}

/** Checks the encoder state. Returns true for an error and false for flow detected.
 */
bool Flow_detector::check(){
  bool flow_error = false;
#ifdef ENCODER_ENABLED
  flow_error = check_encoder();
#endif ENCODER_ENABLED
  return flow_error;
}

#ifdef ENCODER_ENABLED
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
#endif ENCODER_ENABLED
