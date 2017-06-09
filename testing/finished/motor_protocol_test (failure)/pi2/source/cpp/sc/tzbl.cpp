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
unsigned tzflmovement = 0;


// internal variables:
unsigned tzflposition = 0;
unsigned tzflstate = 0;


// prototype:
void tzflsetstep(signed);


// function declaration:
void tzflsetstep(signed movement){
    if (movement == 1){
        if (tzflstate == 0 || tzflstate == 1){
            digitalWrite(tzfl1a, LOW);
            digitalWrite(tzfl1b, HIGH);
            digitalWrite(tzfl2a, HIGH);
            digitalWrite(tzfl2b, LOW);
            tzflstate = 2;tzflposition++;}
        else if (tzflstate == 2){
            digitalWrite(tzfl1a, LOW);
            digitalWrite(tzfl1b, HIGH);
            digitalWrite(tzfl2a, LOW);
            digitalWrite(tzfl2b, HIGH);
            tzflstate = 3;tzflposition++;}
        else if (tzflstate == 3){
            digitalWrite(tzfl1a, HIGH);
            digitalWrite(tzfl1b, LOW);
            digitalWrite(tzfl2a, LOW);
            digitalWrite(tzfl2b, HIGH);
            tzflstate = 4;tzflposition++;}
        else if (tzflstate == 4){
            digitalWrite(tzfl1a, HIGH);
            digitalWrite(tzfl1b, LOW);
            digitalWrite(tzfl2a, HIGH);
            digitalWrite(tzfl2b, LOW);
            tzflstate = 1;tzflposition++;}}
    else if (movement == 2){
        if (tzflstate == 0 || tzflstate == 1){
            digitalWrite(tzfl1a, HIGH);
            digitalWrite(tzfl1b, LOW);
            digitalWrite(tzfl2a, LOW);
            digitalWrite(tzfl2b, HIGH);
            tzflstate = 4;tzflposition--;}
        else if (tzflstate == 2){
            digitalWrite(tzfl1a, HIGH);
            digitalWrite(tzfl1b, LOW);
            digitalWrite(tzfl2a, HIGH);
            digitalWrite(tzfl2b, LOW);
            tzflstate = 1;tzflposition--;}
        else if (tzflstate == 3){
            digitalWrite(tzfl1a, LOW);
            digitalWrite(tzfl1b, HIGH);
            digitalWrite(tzfl2a, HIGH);
            digitalWrite(tzfl2b, LOW);
            tzflstate = 2;tzflposition--;}
        else if (tzflstate == 4){
            digitalWrite(tzfl1a, LOW);
            digitalWrite(tzfl1b, HIGH);
            digitalWrite(tzfl2a, LOW);
            digitalWrite(tzfl2b, HIGH);
            tzflstate = 3;tzflposition--;}}
    else if(movement == 0){
        digitalWrite(tzfl1a, LOW);
        digitalWrite(tzfl1b, LOW);
        digitalWrite(tzfl2a, LOW);
        digitalWrite(tzfl2b, LOW);
        tzflstate = 0;tzflposition = 0;}}



