#include "error_handler.h"

Errorhandler errorhandler;

Errorhandler::Errorhandler(){
#ifdef ERROR_HANDLER_ENABLED
  init();
#endif ERROR_HANDLER_ENABLED
}

Errorhandler::~Errorhandler(){

}

void Errorhandler::error_mode(){
#ifdef ERROR_HANDLER_ENABLED
  while(1){
    blink_led();
  }
#endif ERROR_HANDLER_ENABLED
}

void Errorhandler::init(){
  pinMode(PIN_ERROR_LED, OUTPUT);
}

void Errorhandler::blink_led(){
  digitalWrite(PIN_ERROR_LED, HIGH);
  delay(100);
  digitalWrite(PIN_ERROR_LED, LOW);
  delay(100);
}
