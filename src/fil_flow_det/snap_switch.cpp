#include "snap_switch.h"

Snap_switch::Snap_switch(int index){
  index_ = index;
  pin_power = PIN_SNAP_POWER;
  if(index == 1){
    pin_signal = PIN_SNAP_SWITCH;
  } else {
    if(index == 2){
      pin_signal = PIN_SNAP_SWITCH_2;
      errorhandler.non_blocking_error(10000);
      errorhandler.non_blocking_error(10000);
    }
  }
}

Snap_switch::~Snap_switch(){
}

void Snap_switch::init(){
  if(index_)
    init_input_pin(pin_power, output); //Should only be done with the
                                       //first switch, since they use
                                       //the same pin
  init_input_pin(pin_signal, input);
  digitalWrite(pin_power, HIGH);
}

void Snap_switch::test(){
}

void Snap_switch::update_state(){
  //#ifdef SNAP_SWITCH_ENABLED
  if(SNAP_SWITCH_MODE){
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
  }
  //#endif SNAP_SWITCH_ENABLED
}


snap_switch_state Snap_switch::get_state(){
  return current_state;
}
