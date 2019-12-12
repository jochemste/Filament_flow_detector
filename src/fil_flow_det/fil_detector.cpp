#include "fil_detector.h"

#ifdef SNAP_SWITCH_ENABLED
int Snap_switch::nr_switches_ = 0;
#endif SNAP_SWITCH_ENABLED
#ifdef LASER_SENSOR_ENABLED
int Laser_sensor::nr_lasers_ = 0;
#endif LASER_SENSOR_ENABLED

Fil_detector::Fil_detector(bool& fil_runout){
  runout_detected = &fil_runout;
#ifdef SNAP_SWITCH_ENABLED
  snap_switch = new Snap_switch();
  snap_switch->init();
  #ifdef TWO_HEADS_ENABLED
    snap_switch_2 = new Snap_switch();
    snap_switch_2->init();
  #endif TWO_HEADS_ENABLED
#endif SNAP_SWITCH_ENABLED
#ifdef LASER_SENSOR_ENABLED
  laser_sensor = new Laser_sensor();
  #ifdef TWO_HEADS_ENABLED
    laser_sensor_2 = new Laser_sensor();
    laser_sensor_2->init();
  #endif TWO_HEADS_ENABLED
#endif LASER_SENSOR_ENABLED  
}

Fil_detector::~Fil_detector(){
#ifdef SNAP_SWITCH_ENABLED
  delete snap_switch;
  #ifdef TWO_HEADS_ENABLED
    delete snap_switch_2;
  #endif TWO_HEADS_ENABLED
#endif SNAP_SWITCH_ENABLED

#ifdef LASER_SENSOR_ENABLED
  delete laser_sensor;
  #ifdef TWO_HEADS_ENABLED
    delete laser_sensor_2;
  #endif TWO_HEADS_ENABLED
#endif LASER_SENSOR_ENABLED  
}

void Fil_detector::run(){
  *runout_detected = false;
   runout_detected_1 = check();
   if(runout_detected_1){
     *runout_detected = runout_detected_1;
  }
#ifdef TWO_HEADS_ENABLED
   runout_detected_2 = check_2();
   if(runout_detected_1){
     *runout_detected = runout_detected_2;
  }
#endif TWO_HEADS_ENABLED

}

bool Fil_detector::check(){
  bool fil_error = false;
#ifdef SNAP_SWITCH_ENABLED
  if(!fil_error)
    fil_error = check_snap_switch();
#endif SNAP_SWITCH_ENABLED
  
#ifdef LASER_SENSOR_ENABLED
  if(!fil_error)
    fil_error = check_laser_sens();
#endif LASER_SENSOR_ENABLED
    return fil_error;
}

#ifdef TWO_HEADS_ENABLED
bool Fil_detector::check_2(){
  bool fil_error = false;
#ifdef SNAP_SWITCH_ENABLED
  if(!fil_error)
    fil_error = check_snap_switch_2();
#endif SNAP_SWITCH_ENABLED
  
#ifdef LASER_SENSOR_ENABLED
  if(!fil_error)
    fil_error = check_laser_sens_2();
#endif LASER_SENSOR_ENABLED
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

#ifdef LASER_SENSOR_ENABLED
bool Fil_detector::check_laser_sens(){
  laser_sensor->update_state();
  if(laser_sensor->get_state() == E_LFIL_DETECTED)
    return false;
  else
    return true;
}

  #ifdef TWO_HEADS_ENABLED
  bool Fil_detector::check_laser_sens_2(){
    laser_sensor_2->update_state();
    if(laser_sensor_2->get_state() == E_LFIL_DETECTED)
      return false;
    else
      return true;
  }
  #endif TWO_HEADS_ENABLED
#endif LASER_SENSOR_ENABLED
