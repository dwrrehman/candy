/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : cbl.cpp
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
// cbl pi2 motor function. this is what is called to control the movement of the motor.


#ifndef pi2_cbl_dot_cpp
#define pi2_cbl_dot_cpp

// -------- includes -------------
// ssystem includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "cbl.hpp"

// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place
// 
void cblsetstep(signed movement){
    if (movement == 1){
        if (cblstate == 0 || cblstate == 1){
            digitalWrite(cbl1a, LOW);
            digitalWrite(cbl1b, HIGH);
            digitalWrite(cbl2a, HIGH);
            digitalWrite(cbl2b, LOW);
            cblstate = 2;cblposition++;}
        else if (cblstate == 2){
            digitalWrite(cbl1a, LOW);
            digitalWrite(cbl1b, HIGH);
            digitalWrite(cbl2a, LOW);
            digitalWrite(cbl2b, HIGH);
            cblstate = 3;cblposition++;}
        else if (cblstate == 3){
            digitalWrite(cbl1a, HIGH);
            digitalWrite(cbl1b, LOW);
            digitalWrite(cbl2a, LOW);
            digitalWrite(cbl2b, HIGH);
            cblstate = 4;cblposition++;}
        else if (cblstate == 4){
            digitalWrite(cbl1a, HIGH);
            digitalWrite(cbl1b, LOW);
            digitalWrite(cbl2a, HIGH);
            digitalWrite(cbl2b, LOW);
            cblstate = 1;cblposition++;}}
    else if (movement == 2){
        if (cblstate == 0 || cblstate == 1){
            digitalWrite(cbl1a, HIGH);
            digitalWrite(cbl1b, LOW);
            digitalWrite(cbl2a, LOW);
            digitalWrite(cbl2b, HIGH);
            cblstate = 4;cblposition--;}
        else if (cblstate == 2){
            digitalWrite(cbl1a, HIGH);
            digitalWrite(cbl1b, LOW);
            digitalWrite(cbl2a, HIGH);
            digitalWrite(cbl2b, LOW);
            cblstate = 1;cblposition--;}
        else if (cblstate == 3){
            digitalWrite(cbl1a, LOW);
            digitalWrite(cbl1b, HIGH);
            digitalWrite(cbl2a, HIGH);
            digitalWrite(cbl2b, LOW);
            cblstate = 2;cblposition--;}
        else if (cblstate == 4){
            digitalWrite(cbl1a, LOW);
            digitalWrite(cbl1b, HIGH);
            digitalWrite(cbl2a, LOW);
            digitalWrite(cbl2b, HIGH);
            cblstate = 3;cblposition--;}}
    else if(movement == 0){
        digitalWrite(cbl1a, LOW);
        digitalWrite(cbl1b, LOW);
        digitalWrite(cbl2a, LOW);
        digitalWrite(cbl2b, LOW);
        cblstate = 0;cblposition = 0;}}


#endif 
