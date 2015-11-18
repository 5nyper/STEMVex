#ifndef VIKATON_H_   /* Include guard */
#define VIKATON_H_

// prototypes (not needed, but easier to know what's needed for parameters
void moveForward(int x, int y);
void moveBackward(int x, int y);
void turnX(int left, int right, int i);
void clearEncoders();

// Macros

#define MAX_PORT_NUM 127
#define MIN_PORT_NUM -127
#define _90DEG 950
#define LEFT 0
#define RIGHT 1

// function bodies (ROBOTC has no compiling options,
// so I had to put both prototypes and function bodies in the same file
void moveForward(int x, int y) {
	motor[port1] = x;
	motor[port10] = x;
	wait1Msec(y);
}

void moveBackward(int x, int y) {
	if (x > 0) {
		x = x - x - x;
	}
	motor[port1] = x;
	motor[port10] = x;
	wait1Msec(y);
}

void turnX(int dir, int i) {
	if (dir == LEFT) {
		while (nMotorEncoder[leftMotor] < i) {
			motor[leftMotor] = 100;
			motor[rightMotor] = 0;
		}
		clearEncoders();
	}
	else if (dir == RIGHT) {
		while (nMotorEncoder[rightMotor] < i) {
			motor[rightMotor] = 100;
			motor[leftMotor] = 0;
		}
		clearEncoders();
	}
}

void clearEncoders() {
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;
}

// General Notes: http://www.robotc.net/blog/2012/03/07/programming-with-the-new-vex-integrated-motor-encoders/

#endif
