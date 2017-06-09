/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : txfr.cpp
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
// txfr pi3 motor function. this is what is called to control the movement of the motor.

#ifndef pi3_txfr_dot_cpp
#define pi3_txfr_dot_cpp

// -------- includes -------------
// ssystem includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "txfr.hpp"

// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void txfrsetstep(signed movement){
    if (movement == 1){
        if (txfrstate == 0 || txfrstate == 1){
            digitalWrite(txfr1a, LOW);
            digitalWrite(txfr1b, HIGH);
            digitalWrite(txfr2a, HIGH);
            digitalWrite(txfr2b, LOW);
            txfrstate = 2;txfrposition++;}
        else if (txfrstate == 2){
            digitalWrite(txfr1a, LOW);
            digitalWrite(txfr1b, HIGH);
            digitalWrite(txfr2a, LOW);
            digitalWrite(txfr2b, HIGH);
            txfrstate = 3;txfrposition++;}
        else if (txfrstate == 3){
            digitalWrite(txfr1a, HIGH);
            digitalWrite(txfr1b, LOW);
            digitalWrite(txfr2a, LOW);
            digitalWrite(txfr2b, HIGH);
            txfrstate = 4;txfrposition++;}
        else if (txfrstate == 4){
            digitalWrite(txfr1a, HIGH);
            digitalWrite(txfr1b, LOW);
            digitalWrite(txfr2a, HIGH);
            digitalWrite(txfr2b, LOW);
            txfrstate = 1;txfrposition++;}}
    else if (movement == 2){
        if (txfrstate == 0 || txfrstate == 1){
            digitalWrite(txfr1a, HIGH);
            digitalWrite(txfr1b, LOW);
            digitalWrite(txfr2a, LOW);
            digitalWrite(txfr2b, HIGH);
            txfrstate = 4;txfrposition--;}
        else if (txfrstate == 2){
            digitalWrite(txfr1a, HIGH);
            digitalWrite(txfr1b, LOW);
            digitalWrite(txfr2a, HIGH);
            digitalWrite(txfr2b, LOW);
            txfrstate = 1;txfrposition--;}
        else if (txfrstate == 3){
            digitalWrite(txfr1a, LOW);
            digitalWrite(txfr1b, HIGH);
            digitalWrite(txfr2a, HIGH);
            digitalWrite(txfr2b, LOW);
            txfrstate = 2;txfrposition--;}
        else if (txfrstate == 4){
            digitalWrite(txfr1a, LOW);
            digitalWrite(txfr1b, HIGH);
            digitalWrite(txfr2a, LOW);
            digitalWrite(txfr2b, HIGH);
            txfrstate = 3;txfrposition--;}}
    else if(movement == 0){
        digitalWrite(txfr1a, LOW);
        digitalWrite(txfr1b, LOW);
        digitalWrite(txfr2a, LOW);
        digitalWrite(txfr2b, LOW);
        txfrstate = 0;txfrposition = 0;}}


#endif 
