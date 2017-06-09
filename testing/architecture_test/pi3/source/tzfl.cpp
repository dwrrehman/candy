/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : tzfl.cpp
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
// tzfl pi3 motor function. this is what is called to control the movement of the motor.

#ifndef pi3_tzfl_dot_cpp
#define pi3_tzfl_dot_cpp


// -------- includes -------------
// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "tzfl.hpp"


// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void tzflsetstep(signed movement){
    if (movement == 1){
        if (tzflstate == 0 || tzflstate == 1){
            digitalWrite(tzfl1a, LOW);
            digitalWrite(tzfl1b, HIGH);
            digitalWrite(tzfl2a, HIGH);
            digitalWrite(tzfl2b, LOW);
            tzflstate = 2;tzflposition++;}
        else if (tzflstate == 2){
            digitalWrite(tzfl1a, LOW);
            digitalWrite(tzfl1b, HIGH);
            digitalWrite(tzfl2a, LOW);
            digitalWrite(tzfl2b, HIGH);
            tzflstate = 3;tzflposition++;}
        else if (tzflstate == 3){
            digitalWrite(tzfl1a, HIGH);
            digitalWrite(tzfl1b, LOW);
            digitalWrite(tzfl2a, LOW);
            digitalWrite(tzfl2b, HIGH);
            tzflstate = 4;tzflposition++;}
        else if (tzflstate == 4){
            digitalWrite(tzfl1a, HIGH);
            digitalWrite(tzfl1b, LOW);
            digitalWrite(tzfl2a, HIGH);
            digitalWrite(tzfl2b, LOW);
            tzflstate = 1;tzflposition++;}}
    else if (movement == 2){
        if (tzflstate == 0 || tzflstate == 1){
            digitalWrite(tzfl1a, HIGH);
            digitalWrite(tzfl1b, LOW);
            digitalWrite(tzfl2a, LOW);
            digitalWrite(tzfl2b, HIGH);
            tzflstate = 4;tzflposition--;}
        else if (tzflstate == 2){
            digitalWrite(tzfl1a, HIGH);
            digitalWrite(tzfl1b, LOW);
            digitalWrite(tzfl2a, HIGH);
            digitalWrite(tzfl2b, LOW);
            tzflstate = 1;tzflposition--;}
        else if (tzflstate == 3){
            digitalWrite(tzfl1a, LOW);
            digitalWrite(tzfl1b, HIGH);
            digitalWrite(tzfl2a, HIGH);
            digitalWrite(tzfl2b, LOW);
            tzflstate = 2;tzflposition--;}
        else if (tzflstate == 4){
            digitalWrite(tzfl1a, LOW);
            digitalWrite(tzfl1b, HIGH);
            digitalWrite(tzfl2a, LOW);
            digitalWrite(tzfl2b, HIGH);
            tzflstate = 3;tzflposition--;}}
    else if(movement == 0){
        digitalWrite(tzfl1a, LOW);
        digitalWrite(tzfl1b, LOW);
        digitalWrite(tzfl2a, LOW);
        digitalWrite(tzfl2b, LOW);
        tzflstate = 0;tzflposition = 0;}}


     #endif
