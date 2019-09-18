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

// Enable the encoder wheel to detect filament movement
#define ENCODER_ENABLED
  #ifdef ENCODER_ENABLED
  #endif ENCODER_ENABLED

// Enable the snap switch to detect the presence of filament
#define SNAP_SWITCH_ENABLED
  #ifdef SNAP_SWITCH_ENABLED
    // set SNAP_LOGIC_INVERTED to set filament detected with low signal
    #define SNAP_LOGIC_INVERTED false
  #endif SNAP_SWITCH_ENABLED

// Enable the error handler
#define ERROR_HANDLER_ENABLED
  #ifdef ERROR_HANDLER_ENABLED
  #endif ERROR_HANDLER_ENABLED

// Enable test mode
//#define TEST_ENABLED
  #ifdef TEST_ENABLED
  #endif TEST_ENABLED

#endif CONFIGURATION_H
