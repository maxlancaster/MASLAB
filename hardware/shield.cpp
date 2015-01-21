#include <cassert>

#include "shield.h"
#include "mraa.hpp"

#define SHIELD_I2C_ADDR 0x40
#define MS 1000

Shield::Shield() {
  uint8_t registers[] = {
    6,   // output 0
    10,  // output 1
    14,  // output 2
    18,  // output 3
    22,  // output 4
    26,  // output 5
    30,  // output 6
    34,  // output 7
    38,  // output 8
    42,  // output 9
    46,  // output 10
    50,  // output 11
    54,  // output 12
    58,  // output 13
    62,  // output 14
    66   // output 15
  };

  i2c = new mraa::I2c(6);
  initPWM(i2c);
}

void Shield::initPWM(mraa::I2c *i2c) {
  unsigned char writeBuf[2] = {0}; //NOTE: CHANGED TO UNSIGNED
  writeBuf[0] = 0x00; // Write to MODE 1 Register;
  writeBuf[1] = 1 << 4; // Enable Sleep Mode
 
  i2c->address(SHIELD_I2C_ADDR);
  i2c->write(writeBuf, 2);
 
  usleep(10 * MS);

  writeBuf[0] = 0xFE; // Write Prescaler Register
  writeBuf[1] = 0xA3; // Set pwm frequency to ~40 Hz

  i2c->address(SHIELD_I2C_ADDR);
  i2c->write(writeBuf, 2);
  
  writeBuf[0] = 0; // Write to the MODE 1 register
  writeBuf[1] = 1 << 5 // Enable auto increment mode
      | 0 << 4; // Enable the oscillator
        
  i2c->address(SHIELD_I2C_ADDR);
  i2c->write(writeBuf, 2);
}

void Shield::writePWM(mraa::I2c* i2c, int index, double duty) {
  assert(0.0 <= duty && duty <= 1.0);
  assert(0 <= index && index < 16);
  double on = 4095.0 * duty;
  uint16_t onRounded = (uint16_t) on;

  unsigned char writeBuf[5]; //NOTE: CHANGED TO UNSIGNED

  // ON_L
  writeBuf[0] = registers[index];
  writeBuf[1] = 0x00; // ON LSB
  writeBuf[2] = 0x00; // ON MSB
  writeBuf[3] = onRounded & 0xFF; // OFF LSB
  writeBuf[4] = (onRounded >> 8) & 0xFF; // OFF MSB
  i2c->address(SHIELD_I2C_ADDR);
  i2c->write(writeBuf, 5);
}