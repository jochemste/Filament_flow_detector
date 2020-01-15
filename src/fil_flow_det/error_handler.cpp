#include "error_handler.h"

Errorhandler errorhandler;

Errorhandler::Errorhandler(){
  //#ifdef ERROR_HANDLER_ENABLED
  init();
  //#endif ERROR_HANDLER_ENABLED
}

Errorhandler::~Errorhandler(){

}

void Errorhandler::error_mode(){
//#ifdef ERROR_HANDLER_ENABLED
  while(1){
    blink_led();
  }
//#endif ERROR_HANDLER_ENABLED
}

void Errorhandler::non_blocking_error(int del_t){
  //#ifdef ERROR_HANDLER_ENABLED
  blink_led_t(del_t);
  //#endif ERROR_HANDLER_ENABLED
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

void Errorhandler::blink_led_t(int del_t){
  digitalWrite(PIN_ERROR_LED, HIGH);
  delay(del_t);
  digitalWrite(PIN_ERROR_LED, LOW);
  delay(del_t);
}
