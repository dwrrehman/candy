// name: socket_test
// by: dwrr
// date: 1704296.150706

/// version:    0.1   :   1704296.150706

// this is a test program of the sockets, motor protocol, and sc functions

// --------------------- includes -------------------------
// system includes:
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <thread>

#include <wiringPi.h>

// my includes:
#include "h/pin_numbers.h"

#include "cpp/sc/txfl.cpp"
#include "cpp/sc/tzfl.cpp"
#include "cpp/sc/cfl.cpp"
#include "cpp/sc/txfr.cpp"
#include "cpp/sc/tzfr.cpp"
#include "cpp/sc/cfr.cpp"


// --------------------- parameters -------------------------


int portno = 6001;

bool willshutdown = false;

// ------------------ variables ---------------------------


unsigned char response[1];
unsigned char motordata[3];

unsigned control1 = 0;
unsigned control2 = 0;

// for do_m_m()
    std::thread txflthread;
    std::thread txfrthread;
    std::thread tzflthread;
    std::thread tzfrthread;
    std::thread cflthread;
    std::thread cfrthread;
//





void do_motor_movement(int);



// ------------------------- functions -----------------------------



// 6 threads
void do_motor_movement(int sockfd){ 

    // import neocortex array of predictions bits for motor infuence.
    
    
    // pi3 movement execution. 
    if (txflmovement != 3){txflthread = std::thread (txflsetstep, txflmovement);}
    if (txfrmovement != 3){txfrthread = std::thread (txfrsetstep, txfrmovement);}
    if (tzflmovement != 3){tzflthread = std::thread (tzflsetstep, tzflmovement);}
    if (tzfrmovement != 3){tzfrthread = std::thread (tzfrsetstep, tzfrmovement);}
    if (cflmovement != 3){cflthread = std::thread (cflsetstep, cflmovement);}
    if (cfrmovement != 3){cfrthread = std::thread (cfrsetstep, cfrmovement);}
    
    // motor data compression.
    motordata[0] = (unsigned char)(txblmovement << 6 | tzblmovement << 4 | cblmovement << 2 | txbrmovement); 
    motordata[1] = (unsigned char)(tzbrmovement << 6 | cbrmovement << 4 | wledmovement << 2 | control1);
    motordata[2] = (unsigned char)(nxmovement << 6 | nymovement << 4 | gledmovement << 2 | control2);

    write(sockfd,motordata,3);

    response[0] = 0;
    read(sockfd,response,1);

    if (response[0] != 1){
        printf("INTERNAL ERROR: error in receving confirmation of motor exectution\n");
    }


    // close threads.
    
    txflthread.join();
    txfrthread.join();
    tzflthread.join();
    tzfrthread.join();
    cflthread.join();
    cfrthread.join();

}












// ------- main code ---------

int main(void) {

    // intro
    std::cout << "candy - pi3\n" << "this is a test of sockets, the motor protocol, and using sc functions.\n";

  
    // set up gpio
    wiringPiSetupGpio();

    pinMode(txfl1a, OUTPUT);
    pinMode(txfl1b, OUTPUT);
    pinMode(txfl2a, OUTPUT);
    pinMode(txfl2b, OUTPUT);

    pinMode(txfr1a, OUTPUT);
    pinMode(txfr1b, OUTPUT);
    pinMode(txfr2a, OUTPUT);
    pinMode(txfr2b, OUTPUT);

    pinMode(tzfl1a, OUTPUT);
    pinMode(tzfl1b, OUTPUT);
    pinMode(tzfl2a, OUTPUT);
    pinMode(tzfl2b, OUTPUT);

    pinMode(tzfr1a, OUTPUT);
    pinMode(tzfr1b, OUTPUT);
    pinMode(tzfr2a, OUTPUT);
    pinMode(tzfr2b, OUTPUT);

    pinMode(cfl1a, OUTPUT);
    pinMode(cfl1b, OUTPUT);
    pinMode(cfl2a, OUTPUT);
    pinMode(cfl2b, OUTPUT);

    pinMode(cfr1a, OUTPUT);
    pinMode(cfr1b, OUTPUT);
    pinMode(cfr2a, OUTPUT);
    pinMode(cfr2b, OUTPUT);
    
  

// --------------- pi3 sockets -------------------------

    int newsockfd;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) { 
        printf("connecting to pi2: connection failure.\n");
        exit(1);
    }
    else {
        printf("connecting to pi2: connection success.\n");
    }
    
    // testconnection();
    // this is where we could test the connection with LEDs.





    

// ------------------ motor loop ------------------------

    int desiredmotor = -1;
    int direction = 0;
    int givendelay = 0;
    int givensteps = 0;

while(desiredmotor != 0) {

    std::cout << "\t0 : exit the program\n";
    
    std::cout << "\t1 : txfl\n";
    std::cout << "\t2 : tzfl\n";
    std::cout << "\t3 : cfl\n";

    std::cout << "\t4 : txfr\n";
    std::cout << "\t5 : tzfr\n";
    std::cout << "\t6 : cfr\n";

    std::cout << "\t7 : txbl\n";
    std::cout << "\t8 : tzbl\n";
    std::cout << "\t9 : cbl\n";

    std::cout << "\t10 : txbr\n";
    std::cout << "\t11 : tzbr\n";
    std::cout << "\t12 : cbr\n";

    std::cout << "\t13 : nx\n";
    std::cout << "\t14 : ny\n";

    std::cout << "\t15 : wled\n";
    std::cout << "\t16 : gled\n\n";

    std::cout << "input the desired motor to move: ";
    desiredmotor << std::cin;


    std::cout << "\t0 : relaxed\n";
    std::cout << "\t1 : forwards\n";
    std::cout << "\t2 : backwards\n";
    std::cout << "\t3 : hold\n\n";

    std::cout << "input the desired direction: ";
    direction << std::cin;

    std::cout << "input the delay in milliseconds: ";
    givendelay << std::cin;

    std::cout << "input the number of steps: ";
    givensteps << std::cin;

    std::cout << "thank you.\n\n";


    // exectution

    if (desiredmotor == 0) {
        printf("you exited.");
    }

    else if (desiredmotor == 1) {
        txflmovement = direction;
        for (int i = 0; i < givensteps; i++) {
            do_motor_movement(newsockfd);
            delay(givendelay);
        }
        txflmovement = 0;
    }
    else if (desiredmotor == 2) {
        tzflmovement = direction;
        for (int i = 0; i < givensteps; i++) {
            do_motor_movement(newsockfd);
            delay(givendelay);
        }
        tzflmovement = 0;
    }
    else if (desiredmotor == 3) {
        cflmovement = direction;
        for (int i = 0; i < givensteps; i++) {
            do_motor_movement(newsockfd);
            delay(givendelay);
        }
        cflmovement = 0;
    }


    //... repeat


    else {
        std::cout << "error in inputting motor name.\n";
        break;
    }
    
}


printf("...cleaning up now.");

memset(motordata,0,3); // clear previous data 

motordata[1] = 3; // set control command sequence: "SHUTDOWN";
motordata[2] = 3;

write(newsockfd,motordata,3);  // pass over data 

response[0] = 0; // reset ack

read(newsockfd,response,1); // get ack.

if (response[0] != 1) {
    printf("error in shutting down pi2.");
    return 1;
}
else {
    printf("successfully shutdown pi2.");
}



close(newsockfd2);
close(sockfd2);

    
    

if (willshutdown) system("sudo shutdown now");


return 0;}



















