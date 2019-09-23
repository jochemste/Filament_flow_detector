#include "snap_switch.h"

Snap_switch::Snap_switch(){
  // Nothing to be done yet
}

Snap_switch::~Snap_switch(){
  // Nothing to be done yet
}

void Snap_switch::init(){
  init_input_pin(PIN_SNAP_POWER, output);
  init_input_pin(PIN_SNAP_SWITCH, input);
  digitalWrite(PIN_SNAP_POWER, HIGH);
}

void Snap_switch::test(){
  
}

void Snap_switch::update_state(){
  if(digitalRead(PIN_SNAP_SWITCH) == HIGH)
    current_state = E_FIL_DETECTED;
  else
    current_state = E_FIL_NOT_DETECTED;
}


snap_switch_state Snap_switch::get_state(){
  return current_state;
}
