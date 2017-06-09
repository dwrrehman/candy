/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : ny.cpp
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
// ny pi0 motor function. this is what is called to control the movement of the motor.

#ifndef pi0_ny_dot_cpp
#define pi0_ny_dot_cpp


// -------- includes -------------
// ssystem includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "ny.hpp"


// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void nysetstep(signed movement){
    if (movement == 1){
        if (nystate == 0 || nystate == 1){
            digitalWrite(ny1a, LOW);
            digitalWrite(ny1b, HIGH);
            digitalWrite(ny2a, HIGH);
            digitalWrite(ny2b, LOW);
            nystate = 2;nyposition++;}
        else if (nystate == 2){
            digitalWrite(ny1a, LOW);
            digitalWrite(ny1b, HIGH);
            digitalWrite(ny2a, LOW);
            digitalWrite(ny2b, HIGH);
            nystate = 3;nyposition++;}
        else if (nystate == 3){
            digitalWrite(ny1a, HIGH);
            digitalWrite(ny1b, LOW);
            digitalWrite(ny2a, LOW);
            digitalWrite(ny2b, HIGH);
            nystate = 4;nyposition++;}
        else if (nystate == 4){
            digitalWrite(ny1a, HIGH);
            digitalWrite(ny1b, LOW);
            digitalWrite(ny2a, HIGH);
            digitalWrite(ny2b, LOW);
            nystate = 1;nyposition++;}}
    else if (movement == 2){
        if (nystate == 0 || nystate == 1){
            digitalWrite(ny1a, HIGH);
            digitalWrite(ny1b, LOW);
            digitalWrite(ny2a, LOW);
            digitalWrite(ny2b, HIGH);
            nystate = 4;nyposition--;}
        else if (nystate == 2){
            digitalWrite(ny1a, HIGH);
            digitalWrite(ny1b, LOW);
            digitalWrite(ny2a, HIGH);
            digitalWrite(ny2b, LOW);
            nystate = 1;nyposition--;}
        else if (nystate == 3){
            digitalWrite(ny1a, LOW);
            digitalWrite(ny1b, HIGH);
            digitalWrite(ny2a, HIGH);
            digitalWrite(ny2b, LOW);
            nystate = 2;nyposition--;}
        else if (nystate == 4){
            digitalWrite(ny1a, LOW);
            digitalWrite(ny1b, HIGH);
            digitalWrite(ny2a, LOW);
            digitalWrite(ny2b, HIGH);
            nystate = 3;nyposition--;}}
    else if(movement == 0){
        digitalWrite(ny1a, LOW);
        digitalWrite(ny1b, LOW);
        digitalWrite(ny2a, LOW);
        digitalWrite(ny2b, LOW);
        nystate = 0;nyposition = 0;}}

#endif 
