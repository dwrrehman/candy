/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : txbl.cpp
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
// txbl pi2 motor function. this is what is called to control the movement of the motor.


#ifndef pi2_txbl_dot_cpp
#define pi2_txbl_dot_cpp

// -------- includes -------------
// ssystem includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "txbl.hpp"

// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place

void txblsetstep(signed movement){
    if (movement == 1){
        if (txblstate == 0 || txblstate == 1){
            digitalWrite(txbl1a, LOW);
            digitalWrite(txbl1b, HIGH);
            digitalWrite(txbl2a, HIGH);
            digitalWrite(txbl2b, LOW);
            txblstate = 2;txblposition++;}
        else if (txblstate == 2){
            digitalWrite(txbl1a, LOW);
            digitalWrite(txbl1b, HIGH);
            digitalWrite(txbl2a, LOW);
            digitalWrite(txbl2b, HIGH);
            txblstate = 3;txblposition++;}
        else if (txblstate == 3){
            digitalWrite(txbl1a, HIGH);
            digitalWrite(txbl1b, LOW);
            digitalWrite(txbl2a, LOW);
            digitalWrite(txbl2b, HIGH);
            txblstate = 4;txblposition++;}
        else if (txblstate == 4){
            digitalWrite(txbl1a, HIGH);
            digitalWrite(txbl1b, LOW);
            digitalWrite(txbl2a, HIGH);
            digitalWrite(txbl2b, LOW);
            txblstate = 1;txblposition++;}}
    else if (movement == 2){
        if (txblstate == 0 || txblstate == 1){
            digitalWrite(txbl1a, HIGH);
            digitalWrite(txbl1b, LOW);
            digitalWrite(txbl2a, LOW);
            digitalWrite(txbl2b, HIGH);
            txblstate = 4;txblposition--;}
        else if (txblstate == 2){
            digitalWrite(txbl1a, HIGH);
            digitalWrite(txbl1b, LOW);
            digitalWrite(txbl2a, HIGH);
            digitalWrite(txbl2b, LOW);
            txblstate = 1;txblposition--;}
        else if (txblstate == 3){
            digitalWrite(txbl1a, LOW);
            digitalWrite(txbl1b, HIGH);
            digitalWrite(txbl2a, HIGH);
            digitalWrite(txbl2b, LOW);
            txblstate = 2;txblposition--;}
        else if (txblstate == 4){
            digitalWrite(txbl1a, LOW);
            digitalWrite(txbl1b, HIGH);
            digitalWrite(txbl2a, LOW);
            digitalWrite(txbl2b, HIGH);
            txblstate = 3;txblposition--;}}
    else if(movement == 0){
        digitalWrite(txbl1a, LOW);
        digitalWrite(txbl1b, LOW);
        digitalWrite(txbl2a, LOW);
        digitalWrite(txbl2b, LOW);
        txblstate = 0;txblposition = 0;}}


#endif 
