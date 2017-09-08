#include<wiringPi.h>

#ifndef STEPANGLE
#define STEPANGLE 1.8
#endif

#ifndef STEPS
#define STEPS 200
#endif

static int pina,pinb,pinc,pind;
static int state;

void setup(int a, int b, int c,int d) {

	wiringPiSetup();

	pinMode(a,OUTPUT);
	pinMode(b,OUTPUT);
	pinMode(c,OUTPUT);
	pinMode(d,OUTPUT);

	pina=a;
	pinb=b;
	pinc=c;
	pind=d;
}
	

void write(int st) {
	digitalWrite(pina,st>>3);
	digitalWrite(pinb,(st>>2)&1);
	digitalWrite(pinc,(st>>1)&1);
	digitalWrite(pind,st&1);

	state = st;
}

void oneStep() {
	switch(state) {
		case 10:
			write(6);
			break;
		case 6:
			write(5);
			break;
		case 5:
			write(9);
			break;
		case 9:
			write(10);
			break;
		default:
			write(10);
			break;
	}
}

void rotatesd(int steps,int del) {
	int i;
	for (i=0; i<steps; i++) {
		oneStep();
		delay(del);
	}
}

void rotated(float angle,int del) {
	int steps = angle/ STEPANGLE ;
	rotate(steps,del);
}

void rotate(float angle,float speed) {
	int steps = angle/ STEPANGLE ;
	int del = 60000/( STEPS *speed);
	rotatesd(steps,del);
}
