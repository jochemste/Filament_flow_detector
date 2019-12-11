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
  *runout_detected = false;
   runout_detected_1 = check();
   if(runout_detected_1){
     *runout_detected = runout_detected_1;
  }
#ifdef TWO_HEADS_ENABLED
   runout_detected_2 = check();
   if(runout_detected_1){
     *runout_detected = runout_detected_2;
  }
#endif TWO_HEADS_ENABLED

}

bool Fil_detector::check(){
  bool fil_error = false;
#ifdef SNAP_SWITCH_ENABLED
  fil_error = check_snap_switch();
#endif SNAP_SWITCH_ENABLED
    return fil_error;
}

#ifdef TWO_HEADS_ENABLED
bool Fil_detector::check_2(){
  bool fil_error = false;
#ifdef SNAP_SWITCH_ENABLED
  fil_error = check_snap_switch_2();
#endif SNAP_SWITCH_ENABLED
    return fil_error;
}
#endif TWO_HEADS_ENABLED

bool Fil_detector::get_error(){
  return runout_detected_1;
}
#ifdef TWO_HEADS_ENABLED
bool Fil_detector::get_error_2(){
  return runout_detected_2;
}
#endif TWO_HEADS_ENABLED

#ifdef SNAP_SWITCH_ENABLED
bool Fil_detector::check_snap_switch(){
  snap_switch->update_state();
  if(snap_switch->get_state() == E_FIL_DETECTED)
    return false;
  else
    return true;
}

#ifdef TWO_HEADS_ENABLED
bool Fil_detector::check_snap_switch_2(){
  snap_switch_2->update_state();
  if(snap_switch_2->get_state() == E_FIL_DETECTED)
    return false;
  else
    return true;
}
#endif TWO_HEADS_ENABLED
#endif SNAP_SWITCH_ENABLED
