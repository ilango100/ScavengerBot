CFLAGS = -static -g
LDLIBS = -lwiringPi -lpthread

all: libstepper.a

libstepper.a: stepper.o
	ar rcs libstepper.a stepper.o

.PHONY: clean

clean:
	rm -rf libstepper.o stepper.o

