#include "snap_switch.h"

Snap_switch::Snap_switch(){

}

Snap_switch::~Snap_switch(){

}

void Snap_switch::init(){
  init_input_pin(PIN_SNAP_SWITCH, INPUT);
  //  pinMode(PIN_SNAP_SWITCH, INPUT);
}

void Snap_switch::update_state(){

}

snap_switch_state Snap_switch::get_state(){

}
