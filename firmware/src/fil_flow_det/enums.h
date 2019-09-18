#ifndef ENUMS_H
#define ENUMS_H
// Enums used in code for Encoder, Snap_switch

#include "Configuration.h"

enum pin_mode{
	      input = 0,
	      output = 1
};

#ifdef ENCODER_ENABLED
// Encoder enums
enum enc_pin_state{
		   A_LOW_B_LOW = 0,
		   A_LOW_B_HIGH = 1,
		   A_HIGH_B_LOW = 2,
		   A_HIGH_B_HIGH = 3,
		   ERROR_A_B_PIN
};
enum encoder_state{
		   E_NOT_TURNING,
		   E_TURNING_CW,
		   E_TURNING_CCW,
		   ERROR_ENCODER
};
#endif ENCODER_ENABLED

#ifdef SNAP_SWITCH_ENABLED
// Snap switch enums
enum snap_switch_state{
		       E_FIL_DETECTED,
		       E_FIL_NOT_DETECTED
};
#endif SNAP_SWITCH_ENABLED

#endif ENUMS_H
