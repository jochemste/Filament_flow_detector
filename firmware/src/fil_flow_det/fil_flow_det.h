#ifndef FIL_FLOW_DET_H
#define FIL_FLOW_DET_H

#include "Configuration.h"
#include "pins.h"
#include "enums.h"
#include "flow_detector.h"
#include "fil_detector.h"
#include "error_handler.h"

#include <Arduino.h>

class Fil_flow_det{

public:
  Fil_flow_det();
  ~Fil_flow_det();

  void init();
  void run();

  void stopPrinter();
  void continuePrinter();

private:
  bool flow_error, fil_runout;
  Flow_detector* flow_det;
  Fil_detector* fil_det;
};

extern Fil_flow_det fil_flow_det;

#endif FIL_FLOW_DET_H
