#ifndef VIKATON_H_   /* Include guard */
#define VIKATON_H_

// prototypes
void moveForward(int i);
void moveBackward(int i);
void turnX(int left, int right, int i);

// function bodies (ROBOTC has no compiling options, 
// so I had to put both prototypes and function bodies in the same file
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

void turnX(int left, int right, int i) {
	motor[port1] = left;
	motor[port10] = right;
	wait1Msec(i);
}

#endif
