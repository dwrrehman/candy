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
unsigned cblmovement = 0;


// internal variables:
unsigned cblposition = 0;
unsigned cblstate = 0;


// prototype:
void cblsetstep(signed);


// function declaration:
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



