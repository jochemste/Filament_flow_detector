#include "snap_switch.h"

Snap_switch::Snap_switch(){
  // Nothing to be done yet
  ++nr_switches_;
  if(nr_switches_ < 2){
    pin_power = PIN_SNAP_POWER;
    pin_switch = PIN_SNAP_SWITCH;
  } else {
    pin_power = PIN_SNAP_POWER;
    #ifdef TWO_HEADS_ENABLED
    pin_switch = PIN_SNAP_SWITCH_2;
    #endif TWO_HEADS_ENABLED
  }
}

Snap_switch::~Snap_switch(){
  // Nothing to be done yet
  --nr_switches_;
}

void Snap_switch::init(){
  if(nr_switches_ < 2)
    init_input_pin(pin_power, output); //Should only be done with the first switch,
                                       //since they use the same pin
  init_input_pin(pin_switch, input);
  digitalWrite(pin_power, HIGH);
}

void Snap_switch::test(){
  
}

void Snap_switch::update_state(){
  if(digitalRead(pin_switch) == HIGH)
    current_state = E_FIL_DETECTED;
  else
    current_state = E_FIL_NOT_DETECTED;
}


snap_switch_state Snap_switch::get_state(){
  return current_state;
}
