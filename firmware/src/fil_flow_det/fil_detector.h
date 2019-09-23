#ifndef FIL_DETECTOR_H
#define FIL_DETECTOR_H

#include "Configuration.h"
#include "enums.h"
#ifdef SNAP_SWITCH_ENABLED
  #include "snap_switch.h"
#endif SNAP_SWITCH_ENABLED


class Fil_detector{
 public:
  Fil_detector(bool& fil_runout);
  ~Fil_detector();

  void run();
  bool check();

 private:
  bool* runout_detected;
#ifdef SNAP_SWITCH_ENABLED
  Snap_switch* snap_switch;
  bool check_snap_switch();
#endif SNAP_SWITCH_ENABLED
};

#endif FIL_DETECTOR_H
