/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : nx.cpp
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
// nx pi0 motor function. this is what is called to control the movement of the motor.


#ifndef pi0_nx_dot_cpp
#define pi0_nx_dot_cpp

// -------- includes -------------
// ssystem includes:
#include <wiringPi.h>

// my includes:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"
#include "nx.hpp"

// @param: movement
// the movement variable has values as follows
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place
// 
void nxsetstep(signed movement){
    if (movement == 1){
        if (nxstate == 0 || nxstate == 1){
            digitalWrite(nx1a, LOW);
            digitalWrite(nx1b, HIGH);
            digitalWrite(nx2a, HIGH);
            digitalWrite(nx2b, LOW);
            nxstate = 2;nxposition++;}
        else if (nxstate == 2){
            digitalWrite(nx1a, LOW);
            digitalWrite(nx1b, HIGH);
            digitalWrite(nx2a, LOW);
            digitalWrite(nx2b, HIGH);
            nxstate = 3;nxposition++;}
        else if (nxstate == 3){
            digitalWrite(nx1a, HIGH);
            digitalWrite(nx1b, LOW);
            digitalWrite(nx2a, LOW);
            digitalWrite(nx2b, HIGH);
            nxstate = 4;nxposition++;}
        else if (nxstate == 4){
            digitalWrite(nx1a, HIGH);
            digitalWrite(nx1b, LOW);
            digitalWrite(nx2a, HIGH);
            digitalWrite(nx2b, LOW);
            nxstate = 1;nxposition++;}}
    else if (movement == 2){
        if (nxstate == 0 || nxstate == 1){
            digitalWrite(nx1a, HIGH);
            digitalWrite(nx1b, LOW);
            digitalWrite(nx2a, LOW);
            digitalWrite(nx2b, HIGH);
            nxstate = 4;nxposition--;}
        else if (nxstate == 2){
            digitalWrite(nx1a, HIGH);
            digitalWrite(nx1b, LOW);
            digitalWrite(nx2a, HIGH);
            digitalWrite(nx2b, LOW);
            nxstate = 1;nxposition--;}
        else if (nxstate == 3){
            digitalWrite(nx1a, LOW);
            digitalWrite(nx1b, HIGH);
            digitalWrite(nx2a, HIGH);
            digitalWrite(nx2b, LOW);
            nxstate = 2;nxposition--;}
        else if (nxstate == 4){
            digitalWrite(nx1a, LOW);
            digitalWrite(nx1b, HIGH);
            digitalWrite(nx2a, LOW);
            digitalWrite(nx2b, HIGH);
            nxstate = 3;nxposition--;}}
    else if(movement == 0){
        digitalWrite(nx1a, LOW);
        digitalWrite(nx1b, LOW);
        digitalWrite(nx2a, LOW);
        digitalWrite(nx2b, LOW);
        nxstate = 0;nxposition = 0;}}


#endif 
