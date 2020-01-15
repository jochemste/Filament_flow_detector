#include "encoder.h"

Encoder::Encoder(): turning_(false){
  ++nr_encoders_;
  if(nr_encoders_ < 2){
    pin_a=PIN_A_ENCODER;
    pin_b=PIN_B_ENCODER;
    pin_c=PIN_C_ENCODER;
  } else {
    //#ifdef TWO_HEADS_ENABLED
    if (TWO_HEAD_MODE == true){
      pin_a=PIN_A_ENCODER_2;
      pin_b=PIN_B_ENCODER_2;
      pin_c=PIN_C_ENCODER_2;
    }
    //#endif TWO_HEADS_ENABLED
  }
}

Encoder::~Encoder(){
  --nr_encoders_;
}

void Encoder::init(){
  toggle_initialised();
  if(get_initialised_state()){
    init_input_pin(pin_a, input);
    init_input_pin(pin_b, input);
    init_input_pin(pin_c, output);
  
    digitalWrite(pin_c, HIGH);
  }
}

//                               ab ab ab ab
// encoder clockwise turn order: 00 10 11 01
void Encoder::update_state(){
  previous_pin_state = current_pin_state;
  current_pin_state = read_pins();

  switch(current_pin_state){

  case A_LOW_B_LOW:
    switch(previous_pin_state){
    case A_LOW_B_LOW:
      current_state = E_NOT_TURNING;
      break;
    case A_LOW_B_HIGH:
      current_state = E_TURNING_CW;
      break;
    case A_HIGH_B_LOW:
      current_state = E_TURNING_CCW;
      break;
    case A_HIGH_B_HIGH:
      current_state = ERROR_ENCODER;
      break;
    default:
      current_state = ERROR_ENCODER;
      break;
    }
    break;
    
  case A_LOW_B_HIGH:
    switch(previous_pin_state){
    case A_LOW_B_LOW:
      current_state = E_TURNING_CCW;
      break;
    case A_LOW_B_HIGH:
      current_state = E_NOT_TURNING;
      break;
    case A_HIGH_B_LOW:
      current_state = ERROR_ENCODER;
      break;
    case A_HIGH_B_HIGH:
      current_state = E_TURNING_CW;
      break;
    default:
      current_state = ERROR_ENCODER;
      break;
    }
    break;
    
  case A_HIGH_B_LOW:
    switch(previous_pin_state){
    case A_LOW_B_LOW:
      current_state = E_TURNING_CW;
      break;
    case A_LOW_B_HIGH:
      current_state = ERROR_ENCODER;
      break;
    case A_HIGH_B_LOW:
      current_state = E_NOT_TURNING;
      break;
    case A_HIGH_B_HIGH:
      current_state = E_TURNING_CCW;
      break;
    default:
      current_state = ERROR_ENCODER;
      break;
    }    
    break;
    
  case A_HIGH_B_HIGH:
    switch(previous_pin_state){
    case A_LOW_B_LOW:
      current_state = ERROR_ENCODER;
      break;
    case A_LOW_B_HIGH:
      current_state = E_TURNING_CCW;
      break;
    case A_HIGH_B_LOW:
      current_state = E_TURNING_CW;
      break;
    case A_HIGH_B_HIGH:
      current_state = E_NOT_TURNING;
      break;
    default:
      current_state = ERROR_ENCODER;
      break;
    }    
    break;
    
  default:
    // error
    errorhandler.error_mode();
    break;
  }
}

encoder_state Encoder::get_state(){
  return current_state;
}

enc_pin_state Encoder::read_pins(){
    if(digitalRead(pin_a) == LOW &&
     digitalRead(pin_b) == LOW){
      return A_LOW_B_LOW;
  }
  else if(digitalRead(pin_a) == LOW &&
     digitalRead(pin_b) == HIGH){
    return A_LOW_B_HIGH;
  }
  else if(digitalRead(pin_a) == HIGH &&
	  digitalRead(pin_b) == LOW){
    return A_HIGH_B_LOW;
  }
  else if(digitalRead(pin_a) == HIGH &&
	  digitalRead(pin_b) == HIGH){
    return A_HIGH_B_HIGH;
  }
}
