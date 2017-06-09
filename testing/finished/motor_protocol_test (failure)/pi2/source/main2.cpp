// name: socket_test
// by: dwrr
// date: 1704296.150706

/// version:    0.1   :   1704296.150706

// this is a test program of the basal nuclei functions, to make sure they are effeicent and actually make the motors move.

// ------ includes --------
// system includes:
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include <wiringPi.h>

// my includes:
#include "h/pin_numbers.h"

#include "cpp/sc/txbl.cpp"
#include "cpp/sc/tzbl.cpp"
#include "cpp/sc/cbl.cpp"
#include "cpp/sc/txbr.cpp"
#include "cpp/sc/tzbr.cpp"
#include "cpp/sc/cbr.cpp"
#include "cpp/sc/wled.cpp"


// --------------------- parameters -------------------------


char* hostname = "192.168.9.33";
int portno = 6001;









//  ------------------------variables -----------------------


unsigned char motordata[3];
unsigned char response[1];

unsigned int control1 = 0;

std::thread txblthread;
std::thread txbrthread;
std::thread tzblthread;
std::thread tzbrthread;
std::thread cblthread;
std::thread cbrthread;








// ---------------------- functions ----------------------------


// 6 threads
void do_motor_movement(){ 
    
    // pi3 movement execution. 
    if (txflmovement != 3){txflthread = std::thread (txflsetstep, txflmovement);}
    if (txfrmovement != 3){txfrthread = std::thread (txfrsetstep, txfrmovement);}
    if (tzflmovement != 3){tzflthread = std::thread (tzflsetstep, tzflmovement);}
    if (tzfrmovement != 3){tzfrthread = std::thread (tzfrsetstep, tzfrmovement);}
    if (cflmovement != 3){cflthread = std::thread (cflsetstep, cflmovement);}
    if (cfrmovement != 3){cfrthread = std::thread (cfrsetstep, cfrmovement);}
    wledthread = std::thread (wledsetstate, wledmovement);
    
    // close threads.
    txflthread.join();
    txfrthread.join();
    tzflthread.join();
    tzfrthread.join();
    cflthread.join();
    cfrthread.join();
    wledthread.join();

}








// ------------------------- main code --------------------------

int main(void) {

    // intro
    std::cout << "candy - pi2\n" << "this is a test of sockets, the motor protocol, and using sc functions"

    // set up gpio
    wiringPiSetupGpio();
    
    pinMode(txbl1a, OUTPUT);
    pinMode(txbl1b, OUTPUT);
    pinMode(txbl2a, OUTPUT);
    pinMode(txbl2b, OUTPUT);

    pinMode(tzbl1a, OUTPUT);
    pinMode(tzbl1b, OUTPUT);
    pinMode(tzbl2a, OUTPUT);
    pinMode(tzbl2b, OUTPUT);

    pinMode(cbl1a, OUTPUT);
    pinMode(cbl1b, OUTPUT);
    pinMode(cbl2a, OUTPUT);
    pinMode(cbl2b, OUTPUT);

    pinMode(txbr1a, OUTPUT);
    pinMode(txbr1b, OUTPUT);
    pinMode(txbr2b, OUTPUT);
    pinMode(txbr2a, OUTPUT);

    pinMode(tzbr1a, OUTPUT);
    pinMode(tzbr1b, OUTPUT);
    pinMode(tzbr2a, OUTPUT);
    pinMode(tzbr2b, OUTPUT);

    pinMode(cbr1a, OUTPUT);
    pinMode(cbr1b, OUTPUT);
    pinMode(cbr2a, OUTPUT);
    pinMode(cbr2b, OUTPUT);


// --------------- sockets -------------------------



    int sockfd;    
    struct sockaddr_in serv_addr;
    struct hostent *server;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"no such host.\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        printf("connecting to pi3: connection failure.\n");
        exit(1);
    }
    else {
        printf("connecting to pi3: connection success.\n");
    }
    
    // this is where we could test the connection with LEDs.



    while (true) {

        memset(motordata, 0, 3);
        read(sockfd, motordata, 3);
        
        // extract
        txblmovement = (motordata[0] & 0b11000000) >> 6;
        tzblmovement = (motordata[0] & 0b00110000) >> 4;
        cblmovement = (motordata[0] & 0b00001100) >> 2;
        txbrmovement = motordata[0] & 0b00000011;
        tzbrmovement = (motordata[1] & 0b11000000) >> 6;
        cbrmovement = (motordata[1] & 0b00110000) >> 4;
        wledmovement = (motordata[1] & 0b00001100) >> 2;
        control1 = motordata[1] & 0b00000011;
        control2 = motordata[2] & 0b00000011;

        if (control1 == 3 && control2 == 3) {
            break; // issued shutdown command.
        }
        
        // execute
        do_motor_movement();
        
        // set ACKNOWLEDGE sequence
        response[0] = 1;
        write(sockfd, motordata, 1);
        response[0] = 0;

    }


return 0;}













