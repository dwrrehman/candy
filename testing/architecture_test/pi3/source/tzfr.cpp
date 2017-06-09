/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : tzfr.cpp
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
// tzfr pi3 motor function. this is what is called to control the movement of the motor.

#ifndef pi3_tzfr_dot_cpp
#define pi3_tzfr_dot_cpp


// -------- includes -------------
// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "tzfr.hpp"


// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void tzfrsetstep(signed movement){
    if (movement == 1){
        if (tzfrstate == 0 || tzfrstate == 1){
            digitalWrite(tzfr1a, LOW);
            digitalWrite(tzfr1b, HIGH);
            digitalWrite(tzfr2a, HIGH);
            digitalWrite(tzfr2b, LOW);
            tzfrstate = 2;tzfrposition++;}
        else if (tzfrstate == 2){
            digitalWrite(tzfr1a, LOW);
            digitalWrite(tzfr1b, HIGH);
            digitalWrite(tzfr2a, LOW);
            digitalWrite(tzfr2b, HIGH);
            tzfrstate = 3;tzfrposition++;}
        else if (tzfrstate == 3){
            digitalWrite(tzfr1a, HIGH);
            digitalWrite(tzfr1b, LOW);
            digitalWrite(tzfr2a, LOW);
            digitalWrite(tzfr2b, HIGH);
            tzfrstate = 4;tzfrposition++;}
        else if (tzfrstate == 4){
            digitalWrite(tzfr1a, HIGH);
            digitalWrite(tzfr1b, LOW);
            digitalWrite(tzfr2a, HIGH);
            digitalWrite(tzfr2b, LOW);
            tzfrstate = 1;tzfrposition++;}}
    else if (movement == 2){
        if (tzfrstate == 0 || tzfrstate == 1){
            digitalWrite(tzfr1a, HIGH);
            digitalWrite(tzfr1b, LOW);
            digitalWrite(tzfr2a, LOW);
            digitalWrite(tzfr2b, HIGH);
            tzfrstate = 4;tzfrposition--;}
        else if (tzfrstate == 2){
            digitalWrite(tzfr1a, HIGH);
            digitalWrite(tzfr1b, LOW);
            digitalWrite(tzfr2a, HIGH);
            digitalWrite(tzfr2b, LOW);
            tzfrstate = 1;tzfrposition--;}
        else if (tzfrstate == 3){
            digitalWrite(tzfr1a, LOW);
            digitalWrite(tzfr1b, HIGH);
            digitalWrite(tzfr2a, HIGH);
            digitalWrite(tzfr2b, LOW);
            tzfrstate = 2;tzfrposition--;}
        else if (tzfrstate == 4){
            digitalWrite(tzfr1a, LOW);
            digitalWrite(tzfr1b, HIGH);
            digitalWrite(tzfr2a, LOW);
            digitalWrite(tzfr2b, HIGH);
            tzfrstate = 3;tzfrposition--;}}
    else if(movement == 0){
        digitalWrite(tzfr1a, LOW);
        digitalWrite(tzfr1b, LOW);
        digitalWrite(tzfr2a, LOW);
        digitalWrite(tzfr2b, LOW);
        tzfrstate = 0;tzfrposition = 0;}}


#endif
