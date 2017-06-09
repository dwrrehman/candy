// pi3 motor function. this is what is varied to control the movement of the motor.

// ssystem includes:
#include <wiringPi.h>
// my includes:
#include "pin_numbers.h"


// movement variable. 
//      0 is the relaxed state 
//      1 is forwards 
//      2 is backwards 
//      3 is hold in place
unsigned cbrmovement = 0;


// internal variables:
unsigned cbrposition = 0;
unsigned cbrstate = 0;


// prototype:
void cbrsetstep(signed);


// function declaration:
void cbrsetstep(signed movement){
    if (movement == 1){
        if (cbrstate == 0 || cbrstate == 1){
            digitalWrite(cbr1a, LOW);
            digitalWrite(cbr1b, HIGH);
            digitalWrite(cbr2a, HIGH);
            digitalWrite(cbr2b, LOW);
            cbrstate = 2;cbrposition++;}
        else if (cbrstate == 2){
            digitalWrite(cbr1a, LOW);
            digitalWrite(cbr1b, HIGH);
            digitalWrite(cbr2a, LOW);
            digitalWrite(cbr2b, HIGH);
            cbrstate = 3;cbrposition++;}
        else if (cbrstate == 3){
            digitalWrite(cbr1a, HIGH);
            digitalWrite(cbr1b, LOW);
            digitalWrite(cbr2a, LOW);
            digitalWrite(cbr2b, HIGH);
            cbrstate = 4;cbrposition++;}
        else if (cbrstate == 4){
            digitalWrite(cbr1a, HIGH);
            digitalWrite(cbr1b, LOW);
            digitalWrite(cbr2a, HIGH);
            digitalWrite(cbr2b, LOW);
            cbrstate = 1;cbrposition++;}}
    else if (movement == 2){
        if (cbrstate == 0 || cbrstate == 1){
            digitalWrite(cbr1a, HIGH);
            digitalWrite(cbr1b, LOW);
            digitalWrite(cbr2a, LOW);
            digitalWrite(cbr2b, HIGH);
            cbrstate = 4;cbrposition--;}
        else if (cbrstate == 2){
            digitalWrite(cbr1a, HIGH);
            digitalWrite(cbr1b, LOW);
            digitalWrite(cbr2a, HIGH);
            digitalWrite(cbr2b, LOW);
            cbrstate = 1;cbrposition--;}
        else if (cbrstate == 3){
            digitalWrite(cbr1a, LOW);
            digitalWrite(cbr1b, HIGH);
            digitalWrite(cbr2a, HIGH);
            digitalWrite(cbr2b, LOW);
            cbrstate = 2;cbrposition--;}
        else if (cbrstate == 4){
            digitalWrite(cbr1a, LOW);
            digitalWrite(cbr1b, HIGH);
            digitalWrite(cbr2a, LOW);
            digitalWrite(cbr2b, HIGH);
            cbrstate = 3;cbrposition--;}}
    else if(movement == 0){
        digitalWrite(cbr1a, LOW);
        digitalWrite(cbr1b, LOW);
        digitalWrite(cbr2a, LOW);
        digitalWrite(cbr2b, LOW);
        cbrstate = 0;cbrposition = 0;}}



