/**@file*/

#ifndef LASER_SENSOR_H
#define LASER_SENSOR_H

/**@brief Laser sensor to detect if filament is present.
 * The filament runs in between a laser transmitter and receiver and returns
 * a high or low signal, depending on if the filament is present or not.
 * HIGH signal for filament detected.
*/
#include "enums.h"
#include "sensor.h"
#include "pins.h"
#include "Configuration.h"
#include <Arduino.h>

class Laser_sensor: public Sensor{
 public:
  Laser_sensor();
  ~Laser_sensor();

  void init();
  void test();

  void update_state();
  laser_sensor_state get_state();

 private:
  laser_sensor_state current_state;
  int pin_power; /// Pin used to power the switch
  int pin_signal; /// Pin used to signal the mcu

  static int nr_lasers_;

};

#endif LASER_SENSOR_H
