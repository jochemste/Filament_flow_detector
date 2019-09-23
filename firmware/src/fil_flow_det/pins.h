// Definitions of the pins for the encoder, snap switch, etc
#ifndef PINS_H
#define PINS_H

#include "Configuration.h"

// Rotary encoder
#define PIN_A_ENCODER 2 /// Pin A. Mostly the most left one from the front.
#define PIN_B_ENCODER 4 /// Pin B. Mostly the most right one from the front.
#define PIN_C_ENCODER 3 /// Pin C. Mostly the middle one.

// Snap switch
#define PIN_SNAP_POWER 5 /// Pin to power switch.
#define PIN_SNAP_SWITCH 6 /// Default behaviour: open when switch is not pressed.

// Communication with printer
#define PIN_OUTGOING_PRINTER 7
#ifdef TWO_HEAD_ENABLED
  #define PIN_OUTGOING_PRINTER2 8
#endif TWO_HEAD_ENABLED

// Error LED
#ifdef ERROR_HANDLER_ENABLED
  #define PIN_ERROR_LED 13
#endif ERROR_HANDLER_ENABLED

#endif PINS_H
