// Definitions of the pins for the encoder, snap switch, etc
#ifndef PINS_H
#define PINS_H

#include "Configuration.h"

// Rotary encoder
#ifdef ENCODER_ENABLED
  #define PIN_A_ENCODER 2 /// Pin A. Mostly the most left one from the front.
  #define PIN_B_ENCODER 4 /// Pin B. Mostly the most right one from the front.
  #define PIN_C_ENCODER 3 /// Pin C. Mostly the middle one.
#endif ENCODER_ENABLED

// Snap switch
#ifdef SNAP_SWITCH_ENABLED
  #define PIN_SNAP_SWITCH 5 /// Default behaviour: open when switch is not pressed.
#endif SNAP_SWITCH_ENABLED

// Communication with printer
#define PIN_OUTGOING_PRINTER 6
#ifdef TWO_HEAD_ENABLED
  #define PIN_OUTGOING_PRINTER2 7
#endif TWO_HEAD_ENABLED

// Error LED
#ifdef ERROR_HANDLER_ENABLED
  #define PIN_ERROR_LED 13
#endif ERROR_HANDLER_ENABLED

#endif PINS_H
