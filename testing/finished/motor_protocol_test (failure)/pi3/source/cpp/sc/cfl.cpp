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
unsigned cflmovement = 0;


// internal variables:
unsigned cflposition = 0;
unsigned cflstate = 0;


// prototype:
void cflsetstep(signed);


// function declaration:
void cflsetstep(signed movement){
    if (movement == 1){
        if (cflstate == 0 || cflstate == 1){
            digitalWrite(cfl1a, LOW);
            digitalWrite(cfl1b, HIGH);
            digitalWrite(cfl2a, HIGH);
            digitalWrite(cfl2b, LOW);
            cflstate = 2;cflposition++;}
        else if (cflstate == 2){
            digitalWrite(cfl1a, LOW);
            digitalWrite(cfl1b, HIGH);
            digitalWrite(cfl2a, LOW);
            digitalWrite(cfl2b, HIGH);
            cflstate = 3;cflposition++;}
        else if (cflstate == 3){
            digitalWrite(cfl1a, HIGH);
            digitalWrite(cfl1b, LOW);
            digitalWrite(cfl2a, LOW);
            digitalWrite(cfl2b, HIGH);
            cflstate = 4;cflposition++;}
        else if (cflstate == 4){
            digitalWrite(cfl1a, HIGH);
            digitalWrite(cfl1b, LOW);
            digitalWrite(cfl2a, HIGH);
            digitalWrite(cfl2b, LOW);
            cflstate = 1;cflposition++;}}
    else if (movement == 2){
        if (cflstate == 0 || cflstate == 1){
            digitalWrite(cfl1a, HIGH);
            digitalWrite(cfl1b, LOW);
            digitalWrite(cfl2a, LOW);
            digitalWrite(cfl2b, HIGH);
            cflstate = 4;cflposition--;}
        else if (cflstate == 2){
            digitalWrite(cfl1a, HIGH);
            digitalWrite(cfl1b, LOW);
            digitalWrite(cfl2a, HIGH);
            digitalWrite(cfl2b, LOW);
            cflstate = 1;cflposition--;}
        else if (cflstate == 3){
            digitalWrite(cfl1a, LOW);
            digitalWrite(cfl1b, HIGH);
            digitalWrite(cfl2a, HIGH);
            digitalWrite(cfl2b, LOW);
            cflstate = 2;cflposition--;}
        else if (cflstate == 4){
            digitalWrite(cfl1a, LOW);
            digitalWrite(cfl1b, HIGH);
            digitalWrite(cfl2a, LOW);
            digitalWrite(cfl2b, HIGH);
            cflstate = 3;cflposition--;}}
    else if(movement == 0){
        digitalWrite(cfl1a, LOW);
        digitalWrite(cfl1b, LOW);
        digitalWrite(cfl2a, LOW);
        digitalWrite(cfl2b, LOW);
        cflstate = 0;cflposition = 0;}}



