#include "fil_detector.h"

//#ifdef SNAP_SWITCH_ENABLED
int Snap_switch::nr_switches_ = 0;
//#endif SNAP_SWITCH_ENABLED
//#ifdef LASER_SENSOR_ENABLED
int Laser_sensor::nr_lasers_ = 0;
//#endif LASER_SENSOR_ENABLED

Fil_detector::Fil_detector(bool& fil_runout){
  runout_detected = &fil_runout;
  //#ifdef SNAP_SWITCH_ENABLED
  if(SNAP_SWITCH_MODE){
    snap_switch = new Snap_switch(1);
    snap_switch->init();
    //  #ifdef TWO_HEADS_ENABLED
    if (TWO_HEAD_MODE){
      snap_switch_2 = new Snap_switch(2);
      snap_switch_2->init();
    }
  }
  //#endif TWO_HEADS_ENABLED
  //#endif SNAP_SWITCH_ENABLED

  //#ifdef LASER_SENSOR_ENABLED
  if(LASER_SENSOR_MODE){
    laser_sensor = new Laser_sensor(1);
    laser_sensor->init();
    //  #ifdef TWO_HEADS_ENABLED
    if(TWO_HEAD_MODE){
      laser_sensor_2 = new Laser_sensor(2);
      laser_sensor_2->init();
    }
  }
    //#endif TWO_HEADS_ENABLED
    //#endif LASER_SENSOR_ENABLED  
}

Fil_detector::~Fil_detector(){
  //#ifdef SNAP_SWITCH_ENABLED
  if(SNAP_SWITCH_MODE){
    delete snap_switch;
    //#ifdef TWO_HEADS_ENABLED
    if(TWO_HEAD_MODE){
      delete snap_switch_2;
    }
  }
    //#endif TWO_HEADS_ENABLED
    //#endif SNAP_SWITCH_ENABLED

  //#ifdef LASER_SENSOR_ENABLED
  if(LASER_SENSOR_MODE){
    delete laser_sensor;
    //  #ifdef TWO_HEADS_ENABLED
    if (TWO_HEAD_MODE){
      delete laser_sensor_2;
    }
  }
  //  #endif TWO_HEADS_ENABLED
  //#endif LASER_SENSOR_ENABLED  
}

void Fil_detector::run(){
  *runout_detected = false;
   runout_detected_1 = check();
   if(runout_detected_1){
     *runout_detected = runout_detected_1;
  }
   //#ifdef TWO_HEADS_ENABLED
   if(TWO_HEAD_MODE){
     runout_detected_2 = check_2();
     if(runout_detected_2){
       *runout_detected = runout_detected_2;
     }
   }
   //#endif TWO_HEADS_ENABLED
}

bool Fil_detector::check(){
  bool fil_error = false;
  //#ifdef SNAP_SWITCH_ENABLED
  if(SNAP_SWITCH_MODE){
    if(!fil_error)
      fil_error = check_snap_switch();
  }
  //#endif SNAP_SWITCH_ENABLED
  
  //#ifdef LASER_SENSOR_ENABLED
  if(LASER_SENSOR_MODE){
    if(!fil_error)
      fil_error = check_laser_sens();
    //#endif LASER_SENSOR_ENABLED
  }
    return fil_error;
}

//#ifdef TWO_HEADS_ENABLED
bool Fil_detector::check_2(){
  bool fil_error = false;
  //#ifdef SNAP_SWITCH_ENABLED
  if(SNAP_SWITCH_MODE){
    if(TWO_HEAD_MODE){
      if(!fil_error)
	fil_error = check_snap_switch_2();
    }
  }
  //#endif SNAP_SWITCH_ENABLED
  
  //#ifdef LASER_SENSOR_ENABLED
  if(LASER_SENSOR_MODE){
    if(TWO_HEAD_MODE){
      if(!fil_error)
	fil_error = check_laser_sens_2();
    }
  }
  //#endif LASER_SENSOR_ENABLED
    return fil_error;
}
//#endif TWO_HEADS_ENABLED

bool Fil_detector::get_error(){
  return runout_detected_1;
}

bool Fil_detector::get_error_2(){
  //#ifdef TWO_HEADS_ENABLED
  if(TWO_HEAD_MODE){
    return runout_detected_2;
  } else {
    return false;
  }
  //#else
  //  return false;
  //#endif TWO_HEADS_ENABLED
  }
  

//#ifdef SNAP_SWITCH_ENABLED
bool Fil_detector::check_snap_switch(){
  if(SNAP_SWITCH_MODE){
    snap_switch->update_state();
    if(snap_switch->get_state() == E_FIL_DETECTED)
      return false;
    else
      return true;
  } else {
    return false;
  }
}

bool Fil_detector::check_snap_switch_2(){
  //#ifdef TWO_HEADS_ENABLED
  if(SNAP_SWITCH_MODE){
    if(TWO_HEAD_MODE){
      snap_switch_2->update_state();
      if(snap_switch_2->get_state() == E_FIL_DETECTED)
	return false;
      else
	return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
  //#endif TWO_HEADS_ENABLED
}  
//#endif SNAP_SWITCH_ENABLED

//#ifdef LASER_SENSOR_ENABLED
bool Fil_detector::check_laser_sens(){
  if(LASER_SENSOR_MODE){
  laser_sensor->update_state();
  if(laser_sensor->get_state() == E_LFIL_DETECTED)
    return false;
  else
    return true;
  } else {
    return false;
  }
}

  
bool Fil_detector::check_laser_sens_2(){
  //#ifdef TWO_HEADS_ENABLED
  if(LASER_SENSOR_MODE){
    if(TWO_HEAD_MODE){
      laser_sensor_2->update_state();
      if(laser_sensor_2->get_state() == E_LFIL_DETECTED)
	return false;
      else
	return true;
    } else{
      return false;
    }
  }else{
    return false;
  }
  //#endif TWO_HEADS_ENABLED
}
  
//#endif LASER_SENSOR_ENABLED
