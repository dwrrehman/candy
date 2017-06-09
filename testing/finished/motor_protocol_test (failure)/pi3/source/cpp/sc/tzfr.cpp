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
unsigned tzfrmovement = 0;


// internal variables:
unsigned tzfrposition = 0;
unsigned tzfrstate = 0;


// prototype:
void tzfrsetstep(signed);


// function declaration:
void tzfrsetstep(signed movement){
    if (movement == 1){
        if (tzfrstate == 0 || tzfrstate == 1){
            digitalWrite(tzfr1a, LOW);
            digitalWrite(tzfr1b, HIGH);
            digitalWrite(tzfr2a, HIGH);
            digitalWrite(tzfr2b, LOW);
            tzfrstate = 2;tzfrposition++;}
        else if (tzfrstate == 2){
            digitalWrite(tzfr1a, LOW);
            digitalWrite(tzfr1b, HIGH);
            digitalWrite(tzfr2a, LOW);
            digitalWrite(tzfr2b, HIGH);
            tzfrstate = 3;tzfrposition++;}
        else if (tzfrstate == 3){
            digitalWrite(tzfr1a, HIGH);
            digitalWrite(tzfr1b, LOW);
            digitalWrite(tzfr2a, LOW);
            digitalWrite(tzfr2b, HIGH);
            tzfrstate = 4;tzfrposition++;}
        else if (tzfrstate == 4){
            digitalWrite(tzfr1a, HIGH);
            digitalWrite(tzfr1b, LOW);
            digitalWrite(tzfr2a, HIGH);
            digitalWrite(tzfr2b, LOW);
            tzfrstate = 1;tzfrposition++;}}
    else if (movement == 2){
        if (tzfrstate == 0 || tzfrstate == 1){
            digitalWrite(tzfr1a, HIGH);
            digitalWrite(tzfr1b, LOW);
            digitalWrite(tzfr2a, LOW);
            digitalWrite(tzfr2b, HIGH);
            tzfrstate = 4;tzfrposition--;}
        else if (tzfrstate == 2){
            digitalWrite(tzfr1a, HIGH);
            digitalWrite(tzfr1b, LOW);
            digitalWrite(tzfr2a, HIGH);
            digitalWrite(tzfr2b, LOW);
            tzfrstate = 1;tzfrposition--;}
        else if (tzfrstate == 3){
            digitalWrite(tzfr1a, LOW);
            digitalWrite(tzfr1b, HIGH);
            digitalWrite(tzfr2a, HIGH);
            digitalWrite(tzfr2b, LOW);
            tzfrstate = 2;tzfrposition--;}
        else if (tzfrstate == 4){
            digitalWrite(tzfr1a, LOW);
            digitalWrite(tzfr1b, HIGH);
            digitalWrite(tzfr2a, LOW);
            digitalWrite(tzfr2b, HIGH);
            tzfrstate = 3;tzfrposition--;}}
    else if(movement == 0){
        digitalWrite(tzfr1a, LOW);
        digitalWrite(tzfr1b, LOW);
        digitalWrite(tzfr2a, LOW);
        digitalWrite(tzfr2b, LOW);
        tzfrstate = 0;tzfrposition = 0;}}



