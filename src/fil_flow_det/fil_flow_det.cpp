#include "fil_flow_det.h"

Fil_flow_det fil_flow_det;

Fil_flow_det::Fil_flow_det(): flow_error(false), fil_runout(false){
#ifndef TEST_ENABLED
  flow_det = new Flow_detector(flow_error);
  fil_det = new Fil_detector(fil_runout);
#endif TEST_ENABLED
}

Fil_flow_det::~Fil_flow_det(){
#ifndef TEST_ENABLED
  delete flow_det;
  delete fil_det;
#endif TEST_ENABLED
}

void Fil_flow_det::init(){
  pinMode(PIN_OUTGOING_PRINTER, output);
#ifdef TWO_HEAD_ENABLED
  pinMode(PIN_OUTGOING_PRINTER_2, output);
#endif TWO_HEAD_ENABLED
#ifdef START_SIGNAL_ENABLED
  pinMode(PIN_START, input);
#endif START_SIGNAL_ENABLED
}

void Fil_flow_det::run(){
#ifdef TEST_ENABLED
  
  continuePrinter();

#else

  #ifdef START_SIGNAL_ENABLED
  while(digitalRead(PIN_START) == LOW){ //Check pin state before start
    continuePrinter();
  }
  #endif START_SIGNAL_ENABLED

  fil_det->run();
  flow_det->run();

  if(flow_error || fil_runout){
    if(flow_error){
      #ifdef TWO_HEAD_ENABLED
      if(flow_det->get_error()){
	stopPrinter()
      } else if (flow_det->get_error_2){
	stopPrinter_2()
      }
      #else
      stopPrinter();
      #endif TWO_HEAD_ENABLED
    }

    if(fil_runout){
      #ifdef TWO_HEAD_ENABLED
      if(flow_det->get_error()){
	stopPrinter()
      } else if (flow_det->get_error_2){
	stopPrinter_2()
      }
      #else
      stopPrinter();
      #endif TWO_HEAD_ENABLED
    }
  } else {
    continuePrinter();
  }
  
#endif TEST_ENABLED
}

void Fil_flow_det::stopPrinter(){
  digitalWrite(PIN_OUTGOING_PRINTER, FIL_RUNOUT_LOGIC);
}

void Fil_flow_det::continuePrinter(){
  digitalWrite(PIN_OUTGOING_PRINTER, FIL_PRESENT_LOGIC);
}

#ifdef TWO_HEAD_ENABLED
void Fil_flow_det::stopPrinter_2(){
  digitalWrite(PIN_OUTGOING_PRINTER2, FIL_RUNOUT_LOGIC);
}

void Fil_flow_det::continuePrinter_2(){
  digitalWrite(PIN_OUTGOING_PRINTER2, FIL_PRESENT_LOGIC);
}

#endif TWO_HEAD_ENABLED
