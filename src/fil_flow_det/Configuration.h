#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <Arduino.h>

// Uncomment/comment definitions here to enable or disable them

// Filament runout logic for receiving printer
// Uncomment FIL_RUNOUT_INVERSE to set logic high as signal to stop printer
//#define FIL_RUNOUT_INVERSE
#ifdef FIL_RUNOUT_INVERSE
  #define FIL_RUNOUT_LOGIC HIGH
  #define FIL_PRESENT_LOGIC LOW
#else
  #define FIL_RUNOUT_LOGIC LOW
  #define FIL_PRESENT_LOGIC HIGH
#endif FIL_RUNOUT_INVERSE

// Enable two headed printer support (parallel printing)
#define TWO_HEAD_MODE true
//#define TWO_HEAD_ENABLED
  #ifdef TWO_HEAD_ENABLED
  #endif TWO_HEAD_ENABLED

// Enable the encoder wheel to detect filament movement
#define ENCODER_MODE false
//#define ENCODER_ENABLED
  #ifdef ENCODER_ENABLED
  #endif ENCODER_ENABLED

// Enable the snap switch to detect the presence of filament
#define SNAP_SWITCH_MODE false
//#define SNAP_SWITCH_ENABLED
//#ifdef SNAP_SWITCH_ENABLED
    // set SNAP_LOGIC_INVERTED to set filament detected with low signal
#define SNAP_LOGIC_INVERTED false
//#endif SNAP_SWITCH_ENABLED

// Enable laser sensor
#define LASER_SENSOR_MODE true
//#define LASER_SENSOR_ENABLED
//  #ifdef LASER_SENSOR_ENABLED
  #define LASER_LOGIC_INVERTED false
//  #endif LASER_SENSOR_ENABLED

// Uncomment to enable the accelerometer
//#define ACCELEROMETER_ENABLED
  #ifdef ACCELEROMETER_ENABLED
  #endif ACCELEROMETER_ENABLED

// Enable the error handler
#define ERROR_HANDLER_ENABLED
  #ifdef ERROR_HANDLER_ENABLED
  #endif ERROR_HANDLER_ENABLED

//Uncomment to enable start signal
#define START_SIGNAL_ENABLED
  #ifdef START_SIGNAL_ENABLED
  #endif START_SIGNAL_ENABLED

// Test mode constantly sends the signal to continue to the printer and
// runs the enabled sensor test functions
// Uncomment to enable test mode
//#define TEST_ENABLED
  #ifdef TEST_ENABLED
  #endif TEST_ENABLED

#endif CONFIGURATION_H
