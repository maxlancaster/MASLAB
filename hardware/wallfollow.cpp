#include <csignal>
#include <iostream>
#include <cassert>
#include <cmath>
#include <sys/time.h>
#include <typeinfo>

#include "mraa.hpp"
#include "gyro.h"
#include "motor.h"
#include "piddrive.h"
#include "shield.h"
#include "ir.h"

int running = 1;

void sig_handler(int signo) {
  if (signo == SIGINT) {
    printf("closing spi nicely\n");
    running = 0;
  }
}

int main() {
  //Handle Ctrl-C quit
  signal(SIGINT, sig_handler);

  Shield *shield = new Shield();

  //two motor setup
  Motor left_motor(15, 0);
  Motor right_motor(4, 2);

  Gyro gyro;

  IR medA = IR(2, 6149.816568, 4.468768853);
  IR medB = IR(1, 2391.189039, -0.079559138);

  //was 0.015, 0, 0.4
  //also 0.05, 0, 0.2
  //for medA:
  PIDDrive driveA(&left_motor, &right_motor, shield, 0.00001, 0.0001, 0.2);
  PIDDrive driveB(&left_motor, &right_motor, shield, 0.00001, 0.0001, 0.1);

  int straight = 0;
  int turning = 0;
  double curAngle = gyro.get_angle();
  /*double startDist = medA.getDistance();
  double dist[5] = {startDist, startDist, startDist, startDist, startDist};
  double avg = startDist;
  double sum = 0;
*/
  while (running) {
    /*sum = 0;
    for (int i = 1; i <= 4; i++) {
      dist[i-1] = dist[i];
    }
    dist[4] = medA.getDistance();
    for (int i = 0; i < 5; i++) {
       sum +=  dist[i];
    }
    avg = sum / 5.;
    */
    std::cout << "sensor A: " << medA.getDistance() << "\t";
    std::cout << "sensor B: " << medB.getDistance() << std::endl;    
//std::cout << "avg: " << avg << std::endl;

      /*if (medA.getDistance() < 20 && medB.getDistance() > 30) {
      turning = 0;
      if (straight == 0) {
        curAngle = gyro.get_angle();
      }
      straight++;
      driv.drive(curAngle, gyro.get_angle(), 0.25); //keep driving straight
      std::cout << "straight\t" << "angle: " << curAngle <<  std::endl;
    } else if ((medA.getDistance() < 20 && medB.getDistance() < 30) || (medA.getDistance() > 30)) {
      straight = 0;
      if (turning == 0) {
        curAngle = gyro.get_angle();
      }
      turning++;
      //drive.drive(curAngle + 10, gyro.get_angle(), .2); //turn away from wall
      drive.stop();
      straight = 0;
      sleep(.2);
      std::cout << "turning " << "angle: " << curAngle << std::endl;
    } else {
      drive.drive(gyro.get_angle(), gyro.get_angle(), 0.2);
    }*/
    
    if (medB.getDistance() < 15) {
      driveA.stop();
      driveB.stop();
      while (medB.getDistance() < 30) {
        left_motor.setSpeed(shield, 0.2);
        right_motor.setSpeed(shield, -0.2);
        std::cout << "B" << std::endl;
      }
    } else if (medA.getDistance() > 80) {
      left_motor.setSpeed(shield, 0.2);
      right_motor.setSpeed(shield, -0.2);
      usleep(300000);
    } else {
      turning = 0;
      driveA.drive(15, medA.getDistance(), 0.2);
      std::cout << "A" << std::endl;
      usleep(100000);
    }

    /*
    if (medA.getDistance() < 14) {
       left_motor.setSpeed(shield, 0.2);
       right_motor.setSpeed(shield, -0.15);
    } else if (medA.getDistance() > 16) {
       left_motor.setSpeed(shield, -0.15);
       right_motor.setSpeed(shield, 0.2);
    } else {
       left_motor.setSpeed(shield, 0.2);
       right_motor.setSpeed(shield, 0.2);
    }
    */
    /*if (avg < 30) {
      drive.drive(gyro.get_angle(), gyro.get_angle(), -.25);
    } else {
      drive.drive(gyro.get_angle(), gyro.get_angle(), 0.25);
    }*/
    usleep(50000);
    //sleep(1);
  }
}
