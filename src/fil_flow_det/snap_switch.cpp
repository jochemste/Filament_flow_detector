#include "snap_switch.h"

Snap_switch::Snap_switch(){
  pin_power = PIN_SNAP_POWER;
  if(++nr_switches_ < 2){
    pin_signal = PIN_SNAP_SWITCH;
  } else {
    #ifdef TWO_HEADS_ENABLED
    pin_signal = PIN_SNAP_SWITCH_2;
    #endif TWO_HEADS_ENABLED
  }
}

Snap_switch::~Snap_switch(){
  --nr_switches_;
}

void Snap_switch::init(){
  if(nr_switches_ < 2)
    init_input_pin(pin_power, output); //Should only be done with the first switch,
                                       //since they use the same pin
  init_input_pin(pin_signal, input);
  digitalWrite(pin_power, HIGH);
}

void Snap_switch::test(){
  
}

void Snap_switch::update_state(){
  #ifdef SNAP_SWITCH_ENABLED
  if(SNAP_LOGIC_INVERTED == false){
    if(digitalRead(pin_signal) == HIGH)
      current_state = E_FIL_DETECTED;
    else
      current_state = E_FIL_NOT_DETECTED;
  } else {
    if(digitalRead(pin_signal) == LOW)
      current_state = E_FIL_DETECTED;
    else
      current_state = E_FIL_NOT_DETECTED;
  }
  #endif SNAP_SWITCH_ENABLED
}


snap_switch_state Snap_switch::get_state(){
  return current_state;
}
