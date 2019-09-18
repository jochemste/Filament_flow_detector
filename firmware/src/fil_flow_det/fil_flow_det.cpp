#include "fil_flow_det.h"

Fil_flow_det fil_flow_det;

Fil_flow_det::Fil_flow_det(): stopPrinting(false){
  Fil_flow_det = new Fil_flow_det(stopPrinting);
}

Fil_flow_det::~Fil_flow_det(){

}

void Fil_flow_det::init(){
  pinMode(PIN_OUTGOING_PRINTER, output);
#ifdef TWO_HEAD_ENABLED
  pinMode(PIN_OUTGOING_PRINTER2, output);
#endif TWO_HEAD_ENABLED
}

void Fil_flow_det::run(){

  if(0){
    stopPrinter();
  } else {
    continuePrinter();
  }
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
