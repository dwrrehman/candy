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
unsigned tzbrmovement = 0;


// internal variables:
unsigned tzbrposition = 0;
unsigned tzbrstate = 0;


// prototype:
void tzbrsetstep(signed);


// function declaration:
void tzbrsetstep(signed movement){
    if (movement == 1){
        if (tzbrstate == 0 || tzbrstate == 1){
            digitalWrite(tzbr1a, LOW);
            digitalWrite(tzbr1b, HIGH);
            digitalWrite(tzbr2a, HIGH);
            digitalWrite(tzbr2b, LOW);
            tzbrstate = 2;tzbrposition++;}
        else if (tzbrstate == 2){
            digitalWrite(tzbr1a, LOW);
            digitalWrite(tzbr1b, HIGH);
            digitalWrite(tzbr2a, LOW);
            digitalWrite(tzbr2b, HIGH);
            tzbrstate = 3;tzbrposition++;}
        else if (tzbrstate == 3){
            digitalWrite(tzbr1a, HIGH);
            digitalWrite(tzbr1b, LOW);
            digitalWrite(tzbr2a, LOW);
            digitalWrite(tzbr2b, HIGH);
            tzbrstate = 4;tzbrposition++;}
        else if (tzbrstate == 4){
            digitalWrite(tzbr1a, HIGH);
            digitalWrite(tzbr1b, LOW);
            digitalWrite(tzbr2a, HIGH);
            digitalWrite(tzbr2b, LOW);
            tzbrstate = 1;tzbrposition++;}}
    else if (movement == 2){
        if (tzbrstate == 0 || tzbrstate == 1){
            digitalWrite(tzbr1a, HIGH);
            digitalWrite(tzbr1b, LOW);
            digitalWrite(tzbr2a, LOW);
            digitalWrite(tzbr2b, HIGH);
            tzbrstate = 4;tzbrposition--;}
        else if (tzbrstate == 2){
            digitalWrite(tzbr1a, HIGH);
            digitalWrite(tzbr1b, LOW);
            digitalWrite(tzbr2a, HIGH);
            digitalWrite(tzbr2b, LOW);
            tzbrstate = 1;tzbrposition--;}
        else if (tzbrstate == 3){
            digitalWrite(tzbr1a, LOW);
            digitalWrite(tzbr1b, HIGH);
            digitalWrite(tzbr2a, HIGH);
            digitalWrite(tzbr2b, LOW);
            tzbrstate = 2;tzbrposition--;}
        else if (tzbrstate == 4){
            digitalWrite(tzbr1a, LOW);
            digitalWrite(tzbr1b, HIGH);
            digitalWrite(tzbr2a, LOW);
            digitalWrite(tzbr2b, HIGH);
            tzbrstate = 3;tzbrposition--;}}
    else if(movement == 0){
        digitalWrite(tzbr1a, LOW);
        digitalWrite(tzbr1b, LOW);
        digitalWrite(tzbr2a, LOW);
        digitalWrite(tzbr2b, LOW);
        tzbrstate = 0;tzbrposition = 0;}}



