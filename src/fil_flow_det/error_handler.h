/** @file */

#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include "pins.h"
#include "Configuration.h"
#include <Arduino.h>

/** @brief Class to handle errors and blink and LED*/

class Errorhandler{
 public:
  Errorhandler();
  ~Errorhandler();

  void error_mode();
  void non_blocking_error(int del_t);

 private:
  void init();
  void blink_led();
  void blink_led_t(int del_t);
  
};

extern Errorhandler errorhandler;

#endif ERROR_HANDLER_H
