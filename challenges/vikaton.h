#ifndef VIKATON_H_   /* Include guard */
#define VIKATON_H_

// prototypes (not needed, but easier to know what's needed for parameters
void moveForward(int power, int distance);
void moveBackward(int power, int distance);
void turnX(int direction, int power, int degrees);
void clearEncoders();

// Macros

#define MAX_PORT_NUM 127
#define MIN_PORT_NUM -127
#define _90DEG 950
#define LEFT 0
#define RIGHT 1

// function bodies (ROBOTC has no compiling options,
// so I had to put both prototypes and function bodies in the same file
void moveForward(int power, int distance) {
	clearEncoders();
	while (nMotorEncoder[leftMotor] < distance && nMotorEncoder[rightMotor] < distance) {
		motor[leftMotor] = power;
		motor[rightMotor] = power;
	}
}

void moveBackward(int power, int distance) {
	clearEncoders();
	if (power > 0) {
		power = -power;
	}
	while (nMotorEncoder[leftMotor] < distance && nMotorEncoder[rightMotor] < distance) {
		motor[leftMotor] = power;
		motor[rightMotor] = power;
	}
}

void turnX(int direction, int power, int degrees) {
	clearEncoders();
	if (direction == RIGHT) {
		while (nMotorEncoder[leftMotor] < degrees) {
			motor[leftMotor] = power;
			motor[rightMotor] = 0;
		}
		clearEncoders();
	}
	else if (direction == LEFT) {
		while (nMotorEncoder[rightMotor] < degrees) {
			motor[rightMotor] = power;
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
