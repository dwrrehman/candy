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
unsigned cfrmovement = 0;


// internal variables:
unsigned cfrposition = 0;
unsigned cfrstate = 0;


// prototype:
void cfrsetstep(signed);


// function declaration:
void cfrsetstep(signed movement){
    if (movement == 1){
        if (cfrstate == 0 || cfrstate == 1){
            digitalWrite(cfr1a, LOW);
            digitalWrite(cfr1b, HIGH);
            digitalWrite(cfr2a, HIGH);
            digitalWrite(cfr2b, LOW);
            cfrstate = 2;cfrposition++;}
        else if (cfrstate == 2){
            digitalWrite(cfr1a, LOW);
            digitalWrite(cfr1b, HIGH);
            digitalWrite(cfr2a, LOW);
            digitalWrite(cfr2b, HIGH);
            cfrstate = 3;cfrposition++;}
        else if (cfrstate == 3){
            digitalWrite(cfr1a, HIGH);
            digitalWrite(cfr1b, LOW);
            digitalWrite(cfr2a, LOW);
            digitalWrite(cfr2b, HIGH);
            cfrstate = 4;cfrposition++;}
        else if (cfrstate == 4){
            digitalWrite(cfr1a, HIGH);
            digitalWrite(cfr1b, LOW);
            digitalWrite(cfr2a, HIGH);
            digitalWrite(cfr2b, LOW);
            cfrstate = 1;cfrposition++;}}
    else if (movement == 2){
        if (cfrstate == 0 || cfrstate == 1){
            digitalWrite(cfr1a, HIGH);
            digitalWrite(cfr1b, LOW);
            digitalWrite(cfr2a, LOW);
            digitalWrite(cfr2b, HIGH);
            cfrstate = 4;cfrposition--;}
        else if (cfrstate == 2){
            digitalWrite(cfr1a, HIGH);
            digitalWrite(cfr1b, LOW);
            digitalWrite(cfr2a, HIGH);
            digitalWrite(cfr2b, LOW);
            cfrstate = 1;cfrposition--;}
        else if (cfrstate == 3){
            digitalWrite(cfr1a, LOW);
            digitalWrite(cfr1b, HIGH);
            digitalWrite(cfr2a, HIGH);
            digitalWrite(cfr2b, LOW);
            cfrstate = 2;cfrposition--;}
        else if (cfrstate == 4){
            digitalWrite(cfr1a, LOW);
            digitalWrite(cfr1b, HIGH);
            digitalWrite(cfr2a, LOW);
            digitalWrite(cfr2b, HIGH);
            cfrstate = 3;cfrposition--;}}
    else if(movement == 0){
        digitalWrite(cfr1a, LOW);
        digitalWrite(cfr1b, LOW);
        digitalWrite(cfr2a, LOW);
        digitalWrite(cfr2b, LOW);
        cfrstate = 0;cfrposition = 0;}}



