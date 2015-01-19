#include "sensordata.h"
#include "mraa.hpp"

mraa::Gpio close_IR_F;
mraa::Gpio close_IR_B;
mraa::Gpio close_IR_L;
mraa::Gpio close_IR_R;
  
SensorData::SensorData(int pinF, int pinB, int pinL, int pinR) :
  close_IR_F(pinF), close_IR_B(pinB), close_IR_L(pinL), close_IR_R(pinR) {
  
  close_IR_F.dir(mraa::DIR_IN);
  close_IR_B.dir(mraa::DIR_IN);
  close_IR_L.dir(mraa::DIR_IN);
  close_IR_R.dir(mraa::DIR_IN);
}

void SensorData::collectData() {
  //collect ALL the data!
}

int readF() {
  return close_IR_F.read();
}

int readB() {
  return close_IR_B.read();
}

int readL() {
  return close_IR_L.read();
}

int readR() {
  return close_IR_R.read();
}