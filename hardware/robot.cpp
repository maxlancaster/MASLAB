//main robot file
//compile with:
//g++ gyro.cpp motor.cpp robot.cpp -o robot -lmraa
//[ADD IN OTHER FILES LATER AS NEEDED]

//PINS:
//1
//2 - Short range IR
//3 -
//4 - Right wheel dir
//5 - Right wheel pwm
//6
//7 - DON'T USE!!!!
//8 - Left wheel dir
//9 - Left wheel pwm
//10 - Gyro CS
//11 - Gyro MOSI
//12 - Gyro MISO
//13 - Gyro SCLK

//A0 -
//A1 - Med range IR A
//A2 -
//A3 -
//A4 -
//A5 -

#include <csignal>
#include <iostream>
#include <cassert>
#include <cmath>
#include <sys/time.h>
#include <typeinfo>

#include "mraa.hpp"
#include "encoder.h"
#include "gyro.h"
#include "motor.h"
#include "ultrasonic.h"
#include "ir.h"
#include "servo.h"

int running = 0; //SET BACK TO 1 FOR AUTO

double integral = 0;
double last_diff = 0.0;

struct timeval start;
struct timeval end;

//PID coefficients
double P = 0.05;
double I = 0.0;
double D = 0.2;

void sig_handler(int signo) {
  if (signo == SIGINT) {
    printf("closing spi nicely\n");
    running = 0;
  }
}

/*
//handler for encoder pin A on the left motor
void A_handler(void* args) {
  Encoder *en = (Encoder*)args;
  en->encoderA_handler();
}

//handler for encoder pin B on the left motor
void B_handler(void* args) {
  Encoder *en = (Encoder*)args;
  en->encoderB_handler();
}
*/

//PID drive function
void drive_straight(Motor& left, Motor& right, Gyro& gyro,
                    float desired, float estimated, float speed) {
  gettimeofday(&end, NULL);

  int diffSec = end.tv_sec - start.tv_sec;
  int diffUSec = end.tv_usec - start.tv_usec;
  float dT = (float)diffSec + 0.000001*diffUSec;

  float diff = -desired + estimated; //was - of this
  integral += diff*dT;
  float derivative = diff - last_diff;
  float power = P*diff + I*integral + D*derivative;

  //CHECK DIRECTION
  left.setSpeed(speed - power);
  right.setSpeed(speed + power);

  std::cout << "power: " << power << std::endl;

  gettimeofday(&start, NULL);
  last_diff = diff;
}

int main() {
  //Handle Ctrl-C quit
  signal(SIGINT, sig_handler);

  //two motor setup
  Motor left(5, 4);
  //Motor right(9, 8);
  //Motor lift(2, 3);

  Gyro gyro;
  //IR medA = IR(1, 6149.816568, 4.468768853);

  /*Encoder *left_en = new Encoder(2, 3);
  left_en->A.isr(mraa::EDGE_BOTH, A_handler, left_en);
  left_en->B.isr(mraa::EDGE_BOTH, B_handler, left_en);*/

  Shield *shield = new Shield();

  Servo left_servo(0);
  //Servo right_servo(9);

  mraa::Gpio bottombeam = mraa::Gpio(2);
  bottombeam.dir(mraa::DIR_IN);

  mraa::Gpio topbeam = mraa::Gpio(6);
  topbeam.dir(mraa::DIR_IN);

  mraa::Pwm servo = mraa::Pwm(9);
  servo.enable(true);

  gettimeofday(&start, NULL);

  int last = 0;
  int up = 1;

  //left_servo.setDegree(90);
  //left_servo.setDegree(180 - 120);
  //right_servo.setDegree(120);
  //left.setSpeed(0.2);
  double pos;
  //std::cout << "pos: ";
  //std::cin >> pos;
  running = 1;
  double value = 0;
  while (running && value <= 1) {
    //NEED TO CHECK DESIRED AND ESTIMATED BASED ON GYRO OUTPUT
    //desired should come from external input: cube location or something
    //speed should depend on external input from distance sensors or camera
    //std::cout << left_en.getCounts() << std::endl;
    //drive_straight(left, right, gyro, 0.0, gyro.get_angle(), 0.0);
    //std::cout << "gyro: " << gyro.get_angle() << std::endl;
    //servo.write(0.5);
    //TOGGLE CODE
    
    /*if (topbeam.read() && !last) {
      if (left.read() == 0) {
        left.setSpeed(0.2);
        std::cout << "running" << std::endl;
      } else {
        left.stop();
        std::cout << "stopped" << std::endl;
      }
    }*/
    
    
    /*
    if ((!topbeam.read() && up)) {
      lift.stop(); //stop
      up = 0;
      lift_servo.setDegree(180 - 90);
      right_servo.setDegree(90);
      sleep(2);
    } else if (!bottombeam.read() && !up) {
      lift.stop();
      sleep(1);
      
      //put the doors out
      left_door.setDegree(90);
      right_door.setDegree(90);
      sleep(1);

      //wiggle
      left.setSpeed(0.2);
      right.setSpeed(-0.2);
      usleep(500000);
      left.setSpeed(-0.2);
      right.setSpeed(0.2);
      usleep(250000);
      left.setSpeed(0.2);
      right.setSpeed(-0.2);
      usleep(250000);
      left.setSpeed(-0.2);
      right.setSpeed(0.2);
      usleep(250000);
      left.setSpeed(0.2);
      right.setSpeed(-0.2);
      usleep(125000);

      //put the doors back
      left_door.setDegree(0);
      right_door.setDegree(180);
      sleep(1);

      //grab the blocks
      left_servo.setDegree(180 - 15);
      right_servo.setDegree(15);
      sleep(2);

      up = 1;
    } else if (!topbeam.read() && !up) {
      lift.setSpeed(-0.1); //go down
    } else if (!bottombeam.read() && up) {
      lift.setSpeed(0.15); //go up
    }
    */
    
    left_servo.write(shield, 0.07*value + 0.03);
    std::cout << value << std::endl;
    value += 0.01;
    //servo.write(0.3);
    //left_servo.setDegree(180 - pos);
    //right_servo.setDegree(pos);

    //last = topbeam.read();
    usleep(100000);
  }

  //~Gyro();
}
