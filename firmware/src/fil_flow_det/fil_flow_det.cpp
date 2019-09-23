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
  pinMode(PIN_OUTGOING_PRINTER2, output);
#endif TWO_HEAD_ENABLED
}

void Fil_flow_det::run(){
#ifdef TEST_ENABLED
  
  continuePrinter();

#else

  fil_det->run();
  flow_det->run();

  if(flow_error == true || fil_runout == true){
    stopPrinter();
  } else {
    continuePrinter();
  }
  
#endif TEST_ENABLED
}

void Fil_flow_det::stopPrinter(){
  digitalWrite(PIN_OUTGOING_PRINTER, FIL_RUNOUT_LOGIC);
#ifdef TWO_HEAD_ENABLED
  digitalWrite(PIN_OUTGOING_PRINTER2, FIL_RUNOUT_LOGIC);
#endif TWO_HEAD_ENABLED
}

void Fil_flow_det::continuePrinter(){
  digitalWrite(PIN_OUTGOING_PRINTER, FIL_PRESENT_LOGIC);
#ifdef TWO_HEAD_ENABLED
  digitalWrite(PIN_OUTGOING_PRINTER2, FIL_PRESENT_LOGIC);
#endif TWO_HEAD_ENABLED
}
