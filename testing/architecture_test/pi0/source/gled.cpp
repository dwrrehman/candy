/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : gled.cpp
 *
 *   creator : dwrr
 *   created : 1705033.102142
 *
 *   version : 0.1
 *   touched : 1705033.102324
 *   
 */
/// -------------------------------

// description: 
// pi0 motor neuron function. this is what is called to control the state of the green LED.

#ifndef pi0_gled_dot_cpp
#define pi0_gled_dot_cpp

// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"


void gledsetstate(signed movement){
    if (movement) {
        digitalWrite(gledpin, HIGH);
    }
    else {
        digitalWrite(gledpin, LOW);
    }
}


#endif
