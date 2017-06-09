/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : txfl.cpp
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
// txfl pi3 motor function. this is what is called to control the movement of the motor.


#ifndef pi3_txfl_dot_cpp
#define pi3_txfl_dot_cpp

// -------- includes -------------
// ssystem includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "txfl.hpp"

// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void txflsetstep(signed movement){
    if (movement == 1){
        if (txflstate == 0 || txflstate == 1){
            digitalWrite(txfl1a, LOW);
            digitalWrite(txfl1b, HIGH);
            digitalWrite(txfl2a, HIGH);
            digitalWrite(txfl2b, LOW);
            txflstate = 2;txflposition++;}
        else if (txflstate == 2){
            digitalWrite(txfl1a, LOW);
            digitalWrite(txfl1b, HIGH);
            digitalWrite(txfl2a, LOW);
            digitalWrite(txfl2b, HIGH);
            txflstate = 3;txflposition++;}
        else if (txflstate == 3){
            digitalWrite(txfl1a, HIGH);
            digitalWrite(txfl1b, LOW);
            digitalWrite(txfl2a, LOW);
            digitalWrite(txfl2b, HIGH);
            txflstate = 4;txflposition++;}
        else if (txflstate == 4){
            digitalWrite(txfl1a, HIGH);
            digitalWrite(txfl1b, LOW);
            digitalWrite(txfl2a, HIGH);
            digitalWrite(txfl2b, LOW);
            txflstate = 1;txflposition++;}}
    else if (movement == 2){
        if (txflstate == 0 || txflstate == 1){
            digitalWrite(txfl1a, HIGH);
            digitalWrite(txfl1b, LOW);
            digitalWrite(txfl2a, LOW);
            digitalWrite(txfl2b, HIGH);
            txflstate = 4;txflposition--;}
        else if (txflstate == 2){
            digitalWrite(txfl1a, HIGH);
            digitalWrite(txfl1b, LOW);
            digitalWrite(txfl2a, HIGH);
            digitalWrite(txfl2b, LOW);
            txflstate = 1;txflposition--;}
        else if (txflstate == 3){
            digitalWrite(txfl1a, LOW);
            digitalWrite(txfl1b, HIGH);
            digitalWrite(txfl2a, HIGH);
            digitalWrite(txfl2b, LOW);
            txflstate = 2;txflposition--;}
        else if (txflstate == 4){
            digitalWrite(txfl1a, LOW);
            digitalWrite(txfl1b, HIGH);
            digitalWrite(txfl2a, LOW);
            digitalWrite(txfl2b, HIGH);
            txflstate = 3;txflposition--;}}
    else if(movement == 0){
        digitalWrite(txfl1a, LOW);
        digitalWrite(txfl1b, LOW);
        digitalWrite(txfl2a, LOW);
        digitalWrite(txfl2b, LOW);
        txflstate = 0;txflposition = 0;}}


#endif 
