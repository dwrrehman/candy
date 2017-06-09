/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : wled.cpp
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
// pi2 motor neuron function. this is what is called to control the state of the white LED.

#ifndef pi2_wled_dot_cpp
#define pi2_wled_dot_cpp

// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"


void wledsetstate(signed movement){
    if (movement) {
        digitalWrite(wledpin, HIGH);
    }
    else {
        digitalWrite(wledpin, LOW);
    }
}


#endif
