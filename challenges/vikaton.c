#include "vikaton.h"


void moveForward(int i) {
	motor[port1] = 100;
	motor[port10] = 100;
	wait1Msec(i);
}

void moveBackward(int i) {
	motor[port1] = -100;
	motor[port10] = -100;
	wait1Msec(i);
}
