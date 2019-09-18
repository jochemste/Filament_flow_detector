#ifndef FLOW_DETECTOR_H
#define FLOW_DETECTOR_H

#include "encoder.h"
#include "enums.h"
#include "error_handler.h"
#include <Arduino.h>


class Flow_detector{
 public:
  Flow_detector(bool &air_printing_warning);
  ~Flow_detector();

  void run();
  void check();
  
 private:
  bool* no_flow;
  Encoder* encoder;
};


#endif FLOW_DETECTOR_H
