// Definitions of the pins for the encoder, snap switch, etc
#ifndef PINS_H
#define PINS_H

#include "Configuration.h"

/**
Pin assignment file. Make sure to check the reserved pins at the end of the file to avoid problems.
*/


// Start pin
#ifdef START_SIGNAL_ENABLED
  #define PIN_START 9
#endif START_SIGNAL_ENABLED

// Rotary encoder 1
#define PIN_A_ENCODER 2 /// Pin A. Mostly the most left one from the front.
#define PIN_B_ENCODER 4 /// Pin B. Mostly the most right one from the front.
#define PIN_C_ENCODER 3 /// Pin C. Mostly the middle one.

// Rotary encoder 2
#ifdef TWO_HEAD_ENABLED
  #define PIN_A_ENCODER_2 10 /// Pin A. Mostly most left one from the front.
  #define PIN_B_ENCODER_2 11 /// Pin B. Mostly most right one from the front
  #define PIN_C_ENCODER_2 12 /// Pin C. Mostly the middle one.
#endif TWO_HEAD_ENABLED

// Snap switch
#define PIN_SNAP_POWER 5 /// Pin to power switch(es).
#define PIN_SNAP_SWITCH 6 /// Default behaviour: open when switch is not pressed.
#ifdef TWO_HEAD_ENABLED
  #define PIN_SNAP_SWITCH_2 18 /// A0. Second snap switch for two head mode
#endif TWO_HEAD_ENABLED

// Laser sensor
#define PIN_LASER_POWER 21 /// A3. Powers the laser(s)
#define PIN_LASER_SIG 19 /// A1. Gets the signal from the laser sensor
#ifdef TWO_HEAD_ENABLED
  #define PIN_LASER_SIG_2 20 /// A2. Gets signal from second laser sensor
#endif TWO_HEAD_ENABLED

// Communication with printer
#define PIN_OUTGOING_PRINTER 7 /// Pin to indicate filament error
#ifdef TWO_HEAD_ENABLED
#define PIN_OUTGOING_PRINTER_2 8 /// Pin to indicate second nozzle error
#endif TWO_HEAD_ENABLED

// Error LED
#ifdef ERROR_HANDLER_ENABLED
  #define PIN_ERROR_LED 13
#endif ERROR_HANDLER_ENABLED

/*
Reserved pins:
  13: LED (still usable if you dont mind a blinky LED. 
           By default used as an error LED in this program.)
  14: MISO
  15: SCK
  16: MOSI
  17: SS
*/

#endif PINS_H
