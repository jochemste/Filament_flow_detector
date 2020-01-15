#ifndef FIL_DETECTOR_H
#define FIL_DETECTOR_H

#include "Configuration.h"
#include "enums.h"
#include "snap_switch.h"
#include "laser_sensor.h"


class Fil_detector{
 public:
  Fil_detector(bool& fil_runout);
  ~Fil_detector();

  void run();
  bool check();
  bool check_2();

  bool get_error();
  bool get_error_2();


 private:
  bool* runout_detected;
  bool runout_detected_1;
  bool runout_detected_2;

  Snap_switch* snap_switch;
  Snap_switch* snap_switch_2;

  Laser_sensor* laser_sensor;
  Laser_sensor* laser_sensor_2;

  bool check_snap_switch();
  bool check_laser_sens();
  bool check_snap_switch_2();
  bool check_laser_sens_2();
};

#endif FIL_DETECTOR_H
