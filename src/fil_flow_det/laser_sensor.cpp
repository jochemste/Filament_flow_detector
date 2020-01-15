#include "laser_sensor.h"

Laser_sensor::Laser_sensor(int id){
  id_=id;
  pin_power = PIN_LASER_POWER;
  if (id == 1){
    pin_signal = PIN_LASER_SIG;
  } else if(id == 2) {
    pin_signal = PIN_LASER_SIG_2;
  }
}

Laser_sensor::~Laser_sensor(){
}

void Laser_sensor::init(){
  if(id_==1)
    init_input_pin(pin_power, output);

  init_input_pin(pin_signal, input);
  digitalWrite(pin_power, HIGH);
}

void Laser_sensor::test(){
  
}

void Laser_sensor::update_state(){
  //#ifdef LASER_SENSOR_ENABLED
  if(LASER_SENSOR_MODE){
    if(LASER_LOGIC_INVERTED == false){
      if(digitalRead(pin_signal) == HIGH)
	current_state = E_LFIL_DETECTED;
      else
	current_state = E_LFIL_NOT_DETECTED;
    } else {
      if(digitalRead(pin_signal) == LOW)
	current_state = E_LFIL_DETECTED;
      else
	current_state = E_LFIL_NOT_DETECTED;
    }
  }
  //#else
  //current_state = E_LFIL_DETECTED;
  //#endif LASER_SENSOR_ENABLED
}

laser_sensor_state Laser_sensor::get_state(){
  return current_state;
}
