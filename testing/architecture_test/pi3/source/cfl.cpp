/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : cfl.cpp
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
// cfl pi3 motor function. this is what is called to control the movement of the motor.


#ifndef pi3_cfl_dot_cpp
#define pi3_cfl_dot_cpp

// -------- includes -------------
// ssystem includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "cfl.hpp"

// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place
// 
void cflsetstep(signed movement){
    if (movement == 1){
        if (cflstate == 0 || cflstate == 1){
            digitalWrite(cfl1a, LOW);
            digitalWrite(cfl1b, HIGH);
            digitalWrite(cfl2a, HIGH);
            digitalWrite(cfl2b, LOW);
            cflstate = 2;cflposition++;}
        else if (cflstate == 2){
            digitalWrite(cfl1a, LOW);
            digitalWrite(cfl1b, HIGH);
            digitalWrite(cfl2a, LOW);
            digitalWrite(cfl2b, HIGH);
            cflstate = 3;cflposition++;}
        else if (cflstate == 3){
            digitalWrite(cfl1a, HIGH);
            digitalWrite(cfl1b, LOW);
            digitalWrite(cfl2a, LOW);
            digitalWrite(cfl2b, HIGH);
            cflstate = 4;cflposition++;}
        else if (cflstate == 4){
            digitalWrite(cfl1a, HIGH);
            digitalWrite(cfl1b, LOW);
            digitalWrite(cfl2a, HIGH);
            digitalWrite(cfl2b, LOW);
            cflstate = 1;cflposition++;}}
    else if (movement == 2){
        if (cflstate == 0 || cflstate == 1){
            digitalWrite(cfl1a, HIGH);
            digitalWrite(cfl1b, LOW);
            digitalWrite(cfl2a, LOW);
            digitalWrite(cfl2b, HIGH);
            cflstate = 4;cflposition--;}
        else if (cflstate == 2){
            digitalWrite(cfl1a, HIGH);
            digitalWrite(cfl1b, LOW);
            digitalWrite(cfl2a, HIGH);
            digitalWrite(cfl2b, LOW);
            cflstate = 1;cflposition--;}
        else if (cflstate == 3){
            digitalWrite(cfl1a, LOW);
            digitalWrite(cfl1b, HIGH);
            digitalWrite(cfl2a, HIGH);
            digitalWrite(cfl2b, LOW);
            cflstate = 2;cflposition--;}
        else if (cflstate == 4){
            digitalWrite(cfl1a, LOW);
            digitalWrite(cfl1b, HIGH);
            digitalWrite(cfl2a, LOW);
            digitalWrite(cfl2b, HIGH);
            cflstate = 3;cflposition--;}}
    else if(movement == 0){
        digitalWrite(cfl1a, LOW);
        digitalWrite(cfl1b, LOW);
        digitalWrite(cfl2a, LOW);
        digitalWrite(cfl2b, LOW);
        cflstate = 0;cflposition = 0;}}


#endif 
