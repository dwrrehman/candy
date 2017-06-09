/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : cbr.cpp
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
// cbr pi2 motor function. this is what is called to control the movement of the motor.

#ifndef pi2_cbr_dot_cpp
#define pi2_cbr_dot_cpp


// -------- includes -------------
// ssystem includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "cbr.hpp"


// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void cbrsetstep(signed movement){
    if (movement == 1){
        if (cbrstate == 0 || cbrstate == 1){
            digitalWrite(cbr1a, LOW);
            digitalWrite(cbr1b, HIGH);
            digitalWrite(cbr2a, HIGH);
            digitalWrite(cbr2b, LOW);
            cbrstate = 2;cbrposition++;}
        else if (cbrstate == 2){
            digitalWrite(cbr1a, LOW);
            digitalWrite(cbr1b, HIGH);
            digitalWrite(cbr2a, LOW);
            digitalWrite(cbr2b, HIGH);
            cbrstate = 3;cbrposition++;}
        else if (cbrstate == 3){
            digitalWrite(cbr1a, HIGH);
            digitalWrite(cbr1b, LOW);
            digitalWrite(cbr2a, LOW);
            digitalWrite(cbr2b, HIGH);
            cbrstate = 4;cbrposition++;}
        else if (cbrstate == 4){
            digitalWrite(cbr1a, HIGH);
            digitalWrite(cbr1b, LOW);
            digitalWrite(cbr2a, HIGH);
            digitalWrite(cbr2b, LOW);
            cbrstate = 1;cbrposition++;}}
    else if (movement == 2){
        if (cbrstate == 0 || cbrstate == 1){
            digitalWrite(cbr1a, HIGH);
            digitalWrite(cbr1b, LOW);
            digitalWrite(cbr2a, LOW);
            digitalWrite(cbr2b, HIGH);
            cbrstate = 4;cbrposition--;}
        else if (cbrstate == 2){
            digitalWrite(cbr1a, HIGH);
            digitalWrite(cbr1b, LOW);
            digitalWrite(cbr2a, HIGH);
            digitalWrite(cbr2b, LOW);
            cbrstate = 1;cbrposition--;}
        else if (cbrstate == 3){
            digitalWrite(cbr1a, LOW);
            digitalWrite(cbr1b, HIGH);
            digitalWrite(cbr2a, HIGH);
            digitalWrite(cbr2b, LOW);
            cbrstate = 2;cbrposition--;}
        else if (cbrstate == 4){
            digitalWrite(cbr1a, LOW);
            digitalWrite(cbr1b, HIGH);
            digitalWrite(cbr2a, LOW);
            digitalWrite(cbr2b, HIGH);
            cbrstate = 3;cbrposition--;}}
    else if(movement == 0){
        digitalWrite(cbr1a, LOW);
        digitalWrite(cbr1b, LOW);
        digitalWrite(cbr2a, LOW);
        digitalWrite(cbr2b, LOW);
        cbrstate = 0;cbrposition = 0;}}

#endif 
