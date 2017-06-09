// name: bn_test
// by: dwrr
// date: 1704204.185845

/// version:    0.1   :   1704204.192642

// this is a test program of the basal nuclei functions, to make sure they are effeicent and actually make the motors move.

// ------ includes --------
// system includes:
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include <wiringPi.h>

// my includes:
#include "h/constants/pin_numbers.h"
#include "bn_cfl.cpp"


// ------- main code ---------

int main(void) {

	int distance = 0;
	int givendelay = 0;

    // set up gpio
    wiringPiSetupGpio();
    
    pinMode(cfl1a, OUTPUT);
    pinMode(cfl1b, OUTPUT);
    pinMode(cfl2a, OUTPUT);
    pinMode(cfl2b, OUTPUT);


   	std::cout << "candy - pi3\n" << "this is a program to test the cfl motor, using basal nuclei functions.\n\n";

   	std::cout << "give a delay in milliseconds: ";
   	givendelay << std::cin;

   	std::cout << "give the number of steps: ";
   	distance << std::cin;

   	std::cout << "executing...\n";

   	cflmovement = 1;
   	for (int i = 0; i < distance; i++) {
   		cflsetstep(cflmovement);
   		delay(givendelay);
   	}

   	cflmovement = 2;
   	for (int i = 0; i < distance; i++) {
   		cflsetstep(cflmovement);
   		delay(givendelay);
   	}

   	cflmovement = 0;

   	std::cout << "all done.\n";



}



















