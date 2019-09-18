#include "encoder.h"

Encoder::Encoder(): turning_(false){

}

Encoder::~Encoder(){

}

void Encoder::init(){
/*
  pinMode(PIN_A_ENCODER, INPUT);
  pinMode(PIN_B_ENCODER, INPUT);
  pinMode(PIN_C_ENCODER, OUTPUT);
*/

  init_input_pin(PIN_A_ENCODER, input);
  init_input_pin(PIN_B_ENCODER, input);
  init_input_pin(PIN_C_ENCODER, output);
  
  digitalWrite(PIN_C_ENCODER, HIGH);
}

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
      current_state = E_TURNING_CCW;
      break;
    case A_LOW_B_HIGH:
      current_state = ERROR_ENCODER;
      break;
    case A_HIGH_B_LOW:
      current_state = E_NOT_TURNING;
      break;
    case A_HIGH_B_HIGH:
      current_state = E_TURNING_CW;
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
      current_state = E_TURNING_CW;
      break;
    case A_HIGH_B_LOW:
      current_state = E_TURNING_CCW;
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
    if(digitalRead(PIN_A_ENCODER) == LOW &&
     digitalRead(PIN_B_ENCODER) == LOW){
      return A_LOW_B_LOW;
  }
  else if(digitalRead(PIN_A_ENCODER) == LOW &&
     digitalRead(PIN_B_ENCODER) == HIGH){
    return A_LOW_B_HIGH;
  }
  else if(digitalRead(PIN_A_ENCODER) == HIGH &&
	  digitalRead(PIN_B_ENCODER) == LOW){
    return A_HIGH_B_LOW;
  }
  else if(digitalRead(PIN_A_ENCODER) == HIGH &&
	  digitalRead(PIN_B_ENCODER) == HIGH){
    return A_HIGH_B_HIGH;
  }
}
