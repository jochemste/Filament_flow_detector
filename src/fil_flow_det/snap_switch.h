/**@file*/

#ifndef SNAP_SWITCH_H
#define SNAP_SWITCH_H

/**@brief Snap switch to detect if filament is present. 
 * The filament runs past the sensor, keeping it pressed and returning 
 * either a high of low signal, depending on the connected pin. 
 * Default is HIGH for filament detected.
 */

#include "enums.h"
#include "sensor.h"
#include "pins.h"
#include <Arduino.h>

class Snap_switch: public Sensor{
 public:
  Snap_switch();
  ~Snap_switch();

  void init();
  void test();

  void update_state();
  snap_switch_state get_state();
  
 private:
  snap_switch_state current_state;
  int pin_power; /// Pin used to power the switch
  int pin_switch; ///Pin used to signal the mcu

  static int nr_switches_=0;
};

//extern int Snap_switch::nr_switches_ = 0;

#endif SNAP_SWITCH_H
