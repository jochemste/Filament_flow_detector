#ifndef FIL_DETECTOR_H
#define FIL_DETECTOR_H

#include "Configuration.h"
#include "enums.h"
#ifdef SNAP_SWITCH_ENABLED
  #include "snap_switch.h"
#endif SNAP_SWITCH_ENABLED
#ifdef LASER_SENSOR_ENABLED
  #include "laser_sensor.h"
#endif LASER_SENSOR_ENABLED


class Fil_detector{
 public:
  Fil_detector(bool& fil_runout);
  ~Fil_detector();

  void run();
  bool check();
#ifdef TWO_HEADS_ENABLED
  bool check_2();
#endif TWO_HEADS_ENABLED

  bool get_error();
#ifdef TWO_HEADS_ENABLED
  bool get_error_2();
#endif TWO_HEADS_ENABLED

 private:
  bool* runout_detected;
  bool runout_detected_1;
#ifdef TWO_HEADS_ENABLED
  bool runout_detected_2;
#endif TWO_HEADS_ENABLED

#ifdef SNAP_SWITCH_ENABLED
  Snap_switch* snap_switch;
  #ifdef TWO_HEADS_ENABLED
    Snap_switch* snap_switch_2;
  #endif TWO_HEADS_ENABLED

#ifdef LASER_SENSOR_ENABLED
  Laser_sensor* laser_sensor;
  #ifdef TWO_HEADS_ENABLED
    Laser_sensor* laser_sensor_2;
  #endif TWO_HEADS_ENABLED
#endif LASER_SENSOR_ENABLED
  

  bool check_snap_switch();
  bool check_laser_sens();
#ifdef TWO_HEADS_ENABLED
  bool check_snap_switch_2();
  bool check_laser_sens_2();
#endif TWO_HEADS_ENABLED
#endif SNAP_SWITCH_ENABLED
};

#endif FIL_DETECTOR_H
