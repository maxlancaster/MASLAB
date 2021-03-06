#include <csignal>
#include <iostream>
#include <cassert>
#include <cmath>
#include <sys/time.h>
#include <typeinfo>

/*#include "mraa.hpp"
#include "gyro.h"
#include "motor.h"
#include "piddrive.h"
#include "shield.h"
#include "ir.h"*/

#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/opencv2.hpp"
#include "../vision/cubesearch.h"

int running = 1;

void sig_handler(int signo) {
  if (signo == SIGINT) {
    printf("closing spi nicely\n");
    running = 0;
  }
}

int main() {
  CubeSearch cs;
  VideoCapture cap(0);
  assert(cap.isOpened());

  Mat img;

  //Mat img = imread("../fieldpictures/rgr1.jpg");

  while (running) {
    cap >> img;
    cs.processImage(img);
    if (cs.findStack(img)) {
      std::cout << "found stack" << std::endl;
    }
  }
}
