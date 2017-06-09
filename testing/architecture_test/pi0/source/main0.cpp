/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : main0.cpp
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




// ------------------ variables ---------------------------




// --------------------------






// ---------------- main code -------------------------

int main(void) {

    // intro
    std::cout << "candy - pi0\n" << "this is a test of sockets, the motor protocol, and using sc functions.\n";

    // set up gpio
    wiringPiSetupGpio();

    pinMode(nx1a, OUTPUT);
    pinMode(nx1b, OUTPUT);
    pinMode(nx2a, OUTPUT);
    pinMode(nx2b, OUTPUT);

    pinMode(ny1a, OUTPUT);
    pinMode(ny1b, OUTPUT);
    pinMode(ny2a, OUTPUT);
    pinMode(ny2b, OUTPUT);
    
    pinMode(gledpin, OUTPUT);

// --------------- pi2 sockets -------------------------


    char motor_data[3];
    char camera_data[30000];

    struct sockaddr_in serv_addr;
    struct hostent *server;
    int motor_socket = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname("192.168.9.33");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(motor_socket,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        printf("pi0 to pi3: a connection failure.\n");
        exit(1);
    }
    else {
        printf("connected.\n");
    }

    // testconnection();
    // this is where we could test the connection with LEDs.


// ------------------ motor loop ------------------------

while(true) {

    printf("executing in the loop now..\n");

   spinalcord(motor_socket);
    
}



return 0;}







