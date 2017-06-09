/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : tzbr.cpp
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
// tzbr pi2 motor function. this is what is called to control the movement of the motor.

#ifndef pi2_tzbr_dot_cpp
#define pi2_tzbr_dot_cpp


// -------- includes -------------
// system includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "tzbr.hpp"


// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void tzbrsetstep(signed movement){
    if (movement == 1){
        if (tzbrstate == 0 || tzbrstate == 1){
            digitalWrite(tzbr1a, LOW);
            digitalWrite(tzbr1b, HIGH);
            digitalWrite(tzbr2a, HIGH);
            digitalWrite(tzbr2b, LOW);
            tzbrstate = 2;tzbrposition++;}
        else if (tzbrstate == 2){
            digitalWrite(tzbr1a, LOW);
            digitalWrite(tzbr1b, HIGH);
            digitalWrite(tzbr2a, LOW);
            digitalWrite(tzbr2b, HIGH);
            tzbrstate = 3;tzbrposition++;}
        else if (tzbrstate == 3){
            digitalWrite(tzbr1a, HIGH);
            digitalWrite(tzbr1b, LOW);
            digitalWrite(tzbr2a, LOW);
            digitalWrite(tzbr2b, HIGH);
            tzbrstate = 4;tzbrposition++;}
        else if (tzbrstate == 4){
            digitalWrite(tzbr1a, HIGH);
            digitalWrite(tzbr1b, LOW);
            digitalWrite(tzbr2a, HIGH);
            digitalWrite(tzbr2b, LOW);
            tzbrstate = 1;tzbrposition++;}}
    else if (movement == 2){
        if (tzbrstate == 0 || tzbrstate == 1){
            digitalWrite(tzbr1a, HIGH);
            digitalWrite(tzbr1b, LOW);
            digitalWrite(tzbr2a, LOW);
            digitalWrite(tzbr2b, HIGH);
            tzbrstate = 4;tzbrposition--;}
        else if (tzbrstate == 2){
            digitalWrite(tzbr1a, HIGH);
            digitalWrite(tzbr1b, LOW);
            digitalWrite(tzbr2a, HIGH);
            digitalWrite(tzbr2b, LOW);
            tzbrstate = 1;tzbrposition--;}
        else if (tzbrstate == 3){
            digitalWrite(tzbr1a, LOW);
            digitalWrite(tzbr1b, HIGH);
            digitalWrite(tzbr2a, HIGH);
            digitalWrite(tzbr2b, LOW);
            tzbrstate = 2;tzbrposition--;}
        else if (tzbrstate == 4){
            digitalWrite(tzbr1a, LOW);
            digitalWrite(tzbr1b, HIGH);
            digitalWrite(tzbr2a, LOW);
            digitalWrite(tzbr2b, HIGH);
            tzbrstate = 3;tzbrposition--;}}
    else if(movement == 0){
        digitalWrite(tzbr1a, LOW);
        digitalWrite(tzbr1b, LOW);
        digitalWrite(tzbr2a, LOW);
        digitalWrite(tzbr2b, LOW);
        tzbrstate = 0;tzbrposition = 0;}}


#endif
