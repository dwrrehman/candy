/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : cfr.cpp
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
// cfr pi3 motor function. this is what is called to control the movement of the motor.

#ifndef pi3_cfr_dot_cpp
#define pi3_cfr_dot_cpp


// -------- includes -------------
// ssystem includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "cfr.hpp"


// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void cfrsetstep(signed movement){
    if (movement == 1){
        if (cfrstate == 0 || cfrstate == 1){
            digitalWrite(cfr1a, LOW);
            digitalWrite(cfr1b, HIGH);
            digitalWrite(cfr2a, HIGH);
            digitalWrite(cfr2b, LOW);
            cfrstate = 2;cfrposition++;}
        else if (cfrstate == 2){
            digitalWrite(cfr1a, LOW);
            digitalWrite(cfr1b, HIGH);
            digitalWrite(cfr2a, LOW);
            digitalWrite(cfr2b, HIGH);
            cfrstate = 3;cfrposition++;}
        else if (cfrstate == 3){
            digitalWrite(cfr1a, HIGH);
            digitalWrite(cfr1b, LOW);
            digitalWrite(cfr2a, LOW);
            digitalWrite(cfr2b, HIGH);
            cfrstate = 4;cfrposition++;}
        else if (cfrstate == 4){
            digitalWrite(cfr1a, HIGH);
            digitalWrite(cfr1b, LOW);
            digitalWrite(cfr2a, HIGH);
            digitalWrite(cfr2b, LOW);
            cfrstate = 1;cfrposition++;}}
    else if (movement == 2){
        if (cfrstate == 0 || cfrstate == 1){
            digitalWrite(cfr1a, HIGH);
            digitalWrite(cfr1b, LOW);
            digitalWrite(cfr2a, LOW);
            digitalWrite(cfr2b, HIGH);
            cfrstate = 4;cfrposition--;}
        else if (cfrstate == 2){
            digitalWrite(cfr1a, HIGH);
            digitalWrite(cfr1b, LOW);
            digitalWrite(cfr2a, HIGH);
            digitalWrite(cfr2b, LOW);
            cfrstate = 1;cfrposition--;}
        else if (cfrstate == 3){
            digitalWrite(cfr1a, LOW);
            digitalWrite(cfr1b, HIGH);
            digitalWrite(cfr2a, HIGH);
            digitalWrite(cfr2b, LOW);
            cfrstate = 2;cfrposition--;}
        else if (cfrstate == 4){
            digitalWrite(cfr1a, LOW);
            digitalWrite(cfr1b, HIGH);
            digitalWrite(cfr2a, LOW);
            digitalWrite(cfr2b, HIGH);
            cfrstate = 3;cfrposition--;}}
    else if(movement == 0){
        digitalWrite(cfr1a, LOW);
        digitalWrite(cfr1b, LOW);
        digitalWrite(cfr2a, LOW);
        digitalWrite(cfr2b, LOW);
        cfrstate = 0;cfrposition = 0;}}

#endif 
