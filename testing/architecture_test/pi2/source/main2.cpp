/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : main2.cpp
 *
 *   creator : dwrr
 *   created : 1705033.102142
 *
 *   version : 0.1
 *   touched : 1705313.201933
 *   
 */
/// -------------------------------

// ---------------- includes --------------

// system includes:

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


#include <wiringPi.h>

// my includes:

// constants:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"

// spinal cord:
#include "s.cpp"





// --------------------- parameters -------------------------


int portno = 6001;






// ---------------- main code -------------------------

int main(void) {

    // intro
    std::cout << "candy - pi2\n" << "this is a test of sockets, the motor protocol, and using sc functions.\n";

    // set up gpio
    wiringPiSetupGpio();

    pinMode(txbl1a, OUTPUT);
    pinMode(txbl1b, OUTPUT);
    pinMode(txbl2a, OUTPUT);
    pinMode(txbl2b, OUTPUT);

    pinMode(txbr1a, OUTPUT);
    pinMode(txbr1b, OUTPUT);
    pinMode(txbr2a, OUTPUT);
    pinMode(txbr2b, OUTPUT);

    pinMode(tzbl1a, OUTPUT);
    pinMode(tzbl1b, OUTPUT);
    pinMode(tzbl2a, OUTPUT);
    pinMode(tzbl2b, OUTPUT);

    pinMode(tzbr1a, OUTPUT);
    pinMode(tzbr1b, OUTPUT);
    pinMode(tzbr2a, OUTPUT);
    pinMode(tzbr2b, OUTPUT);

    pinMode(cbl1a, OUTPUT);
    pinMode(cbl1b, OUTPUT);
    pinMode(cbl2a, OUTPUT);
    pinMode(cbl2b, OUTPUT);

    pinMode(cbr1a, OUTPUT);
    pinMode(cbr1b, OUTPUT);
    pinMode(cbr2a, OUTPUT);
    pinMode(cbr2b, OUTPUT);
    
    pinMode(wledpin, OUTPUT);

// --------------- pi2 sockets -------------------------


    char motor_data[3];
    char camera_data[30000];

    struct sockaddr_in serv_addr;
    struct hostent *server;
    int motor_socket = socket(AF_INET, SOCK_STREAM, 0);
    int camera_socket = socket(AF_INET, SOCK_STREAM, 0); 
    server = gethostbyname("192.168.9.33");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(motor_socket,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0 || connect(camera_socket,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        printf("pi2 to pi3: a connection failure.\n");
        exit(1);
    }

    else {
        printf("connected.\n");
    }

    // testconnection();
    // this is where we could test the connection with LEDs.


// ------------------ motor loop ------------------------

while(true) {

   printf("exectuing sc loop...\n");

   spinalcord(motor_socket);
    
}



return 0;}







