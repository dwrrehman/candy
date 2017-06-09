/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : txbr.cpp
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
// txbr pi2 motor function. this is what is called to control the movement of the motor.

#ifndef pi2_txbr_dot_cpp
#define pi2_txbr_dot_cpp

// -------- includes -------------
// ssystem includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "txbr.hpp"

// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void txbrsetstep(signed movement){
    if (movement == 1){
        if (txbrstate == 0 || txbrstate == 1){
            digitalWrite(txbr1a, LOW);
            digitalWrite(txbr1b, HIGH);
            digitalWrite(txbr2a, HIGH);
            digitalWrite(txbr2b, LOW);
            txbrstate = 2;txbrposition++;}
        else if (txbrstate == 2){
            digitalWrite(txbr1a, LOW);
            digitalWrite(txbr1b, HIGH);
            digitalWrite(txbr2a, LOW);
            digitalWrite(txbr2b, HIGH);
            txbrstate = 3;txbrposition++;}
        else if (txbrstate == 3){
            digitalWrite(txbr1a, HIGH);
            digitalWrite(txbr1b, LOW);
            digitalWrite(txbr2a, LOW);
            digitalWrite(txbr2b, HIGH);
            txbrstate = 4;txbrposition++;}
        else if (txbrstate == 4){
            digitalWrite(txbr1a, HIGH);
            digitalWrite(txbr1b, LOW);
            digitalWrite(txbr2a, HIGH);
            digitalWrite(txbr2b, LOW);
            txbrstate = 1;txbrposition++;}}
    else if (movement == 2){
        if (txbrstate == 0 || txbrstate == 1){
            digitalWrite(txbr1a, HIGH);
            digitalWrite(txbr1b, LOW);
            digitalWrite(txbr2a, LOW);
            digitalWrite(txbr2b, HIGH);
            txbrstate = 4;txbrposition--;}
        else if (txbrstate == 2){
            digitalWrite(txbr1a, HIGH);
            digitalWrite(txbr1b, LOW);
            digitalWrite(txbr2a, HIGH);
            digitalWrite(txbr2b, LOW);
            txbrstate = 1;txbrposition--;}
        else if (txbrstate == 3){
            digitalWrite(txbr1a, LOW);
            digitalWrite(txbr1b, HIGH);
            digitalWrite(txbr2a, HIGH);
            digitalWrite(txbr2b, LOW);
            txbrstate = 2;txbrposition--;}
        else if (txbrstate == 4){
            digitalWrite(txbr1a, LOW);
            digitalWrite(txbr1b, HIGH);
            digitalWrite(txbr2a, LOW);
            digitalWrite(txbr2b, HIGH);
            txbrstate = 3;txbrposition--;}}
    else if(movement == 0){
        digitalWrite(txbr1a, LOW);
        digitalWrite(txbr1b, LOW);
        digitalWrite(txbr2a, LOW);
        digitalWrite(txbr2b, LOW);
        txbrstate = 0;txbrposition = 0;}}


#endif 
