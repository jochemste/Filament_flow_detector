#include "flow_detector.h"

Flow_detector::Flow_detector(bool &air_printing_warning){
  no_flow = &air_printing_warning;
  encoder->init();
}

Flow_detector::~Flow_detector(){

}

void Flow_detector::run(){
  check();
}

void Flow_detector::check(){
  encoder->update_state();
  encoder_state enc_state = encoder->get_state();
}
