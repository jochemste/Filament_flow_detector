#include "fil_detector.h"

Fil_detector::Fil_detector(bool& fil_runout){
  runout_detected = &fil_runout;
#ifdef SNAP_SWITCH_ENABLED
  snap_switch = new Snap_switch();
  snap_switch->init();
#endif SNAP_SWITCH_ENABLED
}

Fil_detector::~Fil_detector(){
#ifdef SNAP_SWITCH_ENABLED
  delete snap_switch;
#endif SNAP_SWITCH_ENABLED
}

void Fil_detector::run(){
  *runout_detected = check();
}

bool Fil_detector::check(){
  bool fil_error = false;
#ifdef SNAP_SWITCH_ENABLED
  fil_error = check_snap_switch();
#endif SNAP_SWITCH_ENABLED
    return fil_error;
}

#ifdef SNAP_SWITCH_ENABLED
bool Fil_detector::check_snap_switch(){
  snap_switch->update_state();
  if(snap_switch->get_state() == E_FIL_DETECTED)
    return false;
  else
    return true;
}
#endif SNAP_SWITCH_ENABLED
