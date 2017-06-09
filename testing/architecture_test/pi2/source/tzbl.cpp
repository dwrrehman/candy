/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : tzbl.cpp
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
// tzbl pi2 motor function. this is what is called to control the movement of the motor.

#ifndef pi2_tzbl_dot_cpp
#define pi2_tzbl_dot_cpp


// -------- includes -------------
// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "tzbl.hpp"


// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void tzblsetstep(signed movement){
    if (movement == 1){
        if (tzblstate == 0 || tzblstate == 1){
            digitalWrite(tzbl1a, LOW);
            digitalWrite(tzbl1b, HIGH);
            digitalWrite(tzbl2a, HIGH);
            digitalWrite(tzbl2b, LOW);
            tzblstate = 2;tzblposition++;}
        else if (tzblstate == 2){
            digitalWrite(tzbl1a, LOW);
            digitalWrite(tzbl1b, HIGH);
            digitalWrite(tzbl2a, LOW);
            digitalWrite(tzbl2b, HIGH);
            tzblstate = 3;tzblposition++;}
        else if (tzblstate == 3){
            digitalWrite(tzbl1a, HIGH);
            digitalWrite(tzbl1b, LOW);
            digitalWrite(tzbl2a, LOW);
            digitalWrite(tzbl2b, HIGH);
            tzblstate = 4;tzblposition++;}
        else if (tzblstate == 4){
            digitalWrite(tzbl1a, HIGH);
            digitalWrite(tzbl1b, LOW);
            digitalWrite(tzbl2a, HIGH);
            digitalWrite(tzbl2b, LOW);
            tzblstate = 1;tzblposition++;}}
    else if (movement == 2){
        if (tzblstate == 0 || tzblstate == 1){
            digitalWrite(tzbl1a, HIGH);
            digitalWrite(tzbl1b, LOW);
            digitalWrite(tzbl2a, LOW);
            digitalWrite(tzbl2b, HIGH);
            tzblstate = 4;tzblposition--;}
        else if (tzblstate == 2){
            digitalWrite(tzbl1a, HIGH);
            digitalWrite(tzbl1b, LOW);
            digitalWrite(tzbl2a, HIGH);
            digitalWrite(tzbl2b, LOW);
            tzblstate = 1;tzblposition--;}
        else if (tzblstate == 3){
            digitalWrite(tzbl1a, LOW);
            digitalWrite(tzbl1b, HIGH);
            digitalWrite(tzbl2a, HIGH);
            digitalWrite(tzbl2b, LOW);
            tzblstate = 2;tzblposition--;}
        else if (tzblstate == 4){
            digitalWrite(tzbl1a, LOW);
            digitalWrite(tzbl1b, HIGH);
            digitalWrite(tzbl2a, LOW);
            digitalWrite(tzbl2b, HIGH);
            tzblstate = 3;tzblposition--;}}
    else if(movement == 0){
        digitalWrite(tzbl1a, LOW);
        digitalWrite(tzbl1b, LOW);
        digitalWrite(tzbl2a, LOW);
        digitalWrite(tzbl2b, LOW);
        tzblstate = 0;tzblposition = 0;}}


     #endif
