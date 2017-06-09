/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : s.cpp
 *
 *   creator : dwrr
 *   created : 1705033.102142
 *
 *   version : 0.1
 *   touched : 1705033.102324
 *   
 */
/// -------------------------------

// description: 
// spinal cord function for pi2. 
// takes in the desired motor movement in compressed form, uncompresses it, and executes that movement in a thread. 

#ifndef s_dot_cpp
#define s_dot_cpp

// -------------- includes ---------------

// system includes
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

//my includes

#include "s.hpp" 

// motor neurons:
#include "txbl.cpp"
#include "tzbl.cpp"
#include "cbl.cpp"

#include "txbr.cpp"
#include "tzbr.cpp"
#include "cbr.cpp"

#include "wled.cpp"



// function delcaration:
void spinalcord(int pi3_socket) {

    // used to get the deisred values of exectution.
    unsigned int txblmovement = 0;
    unsigned int tzblmovement = 0;
    unsigned int cblmovement = 0;

    unsigned int txbrmovement = 0;
    unsigned int tzbrmovement = 0;
    unsigned int cbrmovement = 0;

    unsigned int wledmovement = 0;
    unsigned int control1 = 0;
    unsigned int control2 = 0;
    
    // used for communication
	unsigned char motordata[3] = {0};
	unsigned char pi3_response[1] = {0};

    
    // first, read the motor compressed data,
    read(pi3_socket, motordata, 3);
    
    // uncompress data, extract relavant motor commands,
    txblmovement = (motordata[0] & 0b11000000) >> 6;
    txbrmovement = (motordata[0] & 0b00110000) >> 4;
    tzblmovement = (motordata[0] & 0b00001100) >> 2;
    tzbrmovement = motordata[0] & 0b00000011;
    cblmovement = (motordata[1] & 0b11000000) >> 6;
    cbrmovement = (motordata[1] & 0b00110000) >> 4;

    wledmovement = (motordata[1] & 0b00001100) >> 2;

    control1 = motordata[1] & 0b00000011;
    control2 = motordata[2] & 0b00000011;

  
    // pi3 movement execution. 
    if (txblmovement != 3){txblthread = std::thread (txblsetstep, txflmovement);}
    if (txbrmovement != 3){txbrthread = std::thread (txbrsetstep, txfrmovement);}
    if (tzblmovement != 3){tzblthread = std::thread (tzblsetstep, tzflmovement);}
    if (tzbrmovement != 3){tzbrthread = std::thread (tzbrsetstep, tzfrmovement);}
    if (cblmovement != 3){cblthread = std::thread (cblsetstep, cflmovement);}
    if (cbrmovement != 3){cbrthread = std::thread (cbrsetstep, cfrmovement);}
    wledsetstate(wledmovement);


    // this is where we must check the control bits. to see if they are a command sequence. 

    if (control1 == 3 && control2 == 3) {
        // shutdown code
        txblthread.join();
        txbrthread.join();
        tzblthread.join();
        tzbrthread.join();
        cblthread.join();
        cbrthread.join();
        
        system("sudo shutdown now");
    }
    
    // execute other control functions here. 
    // if (control1 == _ && control2 == _) {}


    
    // then set response,
    pi3_response[0] = 1;

    // finally, write the response to the pi3. 
    write(pi3_socket, pi3_response, 1);

    // close threads.
    txblthread.join();
    txbrthread.join();
    tzblthread.join();
    tzbrthread.join();
    cblthread.join();
    cbrthread.join();

}


#endif
