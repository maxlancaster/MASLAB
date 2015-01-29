#include <sys/time.h>

#include "stacksearch.h"
#include "robot_states.h"
#include "sensordata.h"
#include "mraa.hpp"

#include "opencv2/imgproc/imgproc.hpp"
#include "../hardware/piddrive.h"
#include "../vision/cubesearch.h"

StackSearch::StackSearch(CubeSearch* cs, PIDDrive* dr, PIDDrive* a, PIDDrive* b) {
	state_num = STACKSEARCH;

	cubesearch = cs;
	drive = dr;
  driveA = a;
  driveB = b;

	cap = VideoCapture(0);

	count = 0;
}

int StackSearch::getState() {
	return state_num;
}

int StackSearch::process(SensorData data) {
	int next = getNext(data);
	if (next != state_num) {
		return next;
	} else {
		run(data);
		return state_num;
	}
}

int StackSearch::getNext(SensorData data) {
	//only need to check for color once
	cap >> img;
	cubesearch.process(img);
	if (cubesearch.findStack(img)) {
		if (count == 0 && cubesearch.getTopColor(img) != data.rgswitch()) {
			return STACKSEARCH;
		}
		count++;
		return DRIVE;
	} else {
		return STACKSEARCH;
	}
}

void StackSearch::run(SensorData data) {
	//might only work once...
	if (data.getGyroAngle() > 360 || gyro.getGyroAngle() < -360) {
		std::cout << "StackSearch: wall following" << std::endl;
		wallFollow(data);
	} else {
		std::cout << "StackSearch: turning" << std::endl;
		drive.drive(gyro.getGyroAngle() - 20, gyro.getGyroAngle(), 0.2);
		usleep(200000);
	}
}

void StackSearch::wallFollow(SensorData data) {
  if (data.getDistanceB() < 15) {
    driveA.stop();
    driveB.stop();
    while (data.getDistanceB() < 30) {
      driveB.A->setSpeed(shield, 0.2);
      driveB.B->setSpeed(shield, -0.2);
      std::cout << "B" << std::endl;
    }
  } else if (data.getDistanceA() > 80) {
    driveA.A->setSpeed(shield, 0.2);
    driveA.B->setSpeed(shield, -0.2);
    usleep(300000);
  } else {
    driveA.drive(15, data.getDistanceA(), 0.2);
    std::cout << "A" << std::endl;
    usleep(100000);
  }
}