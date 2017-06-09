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
// spinal cord function for pi0. 
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
#include "nx.cpp"
#include "ny.cpp"

#include "gled.cpp"



// function delcaration:
void spinalcord(int pi3_socket) {

    // used to get the deisred values of exectution.
    unsigned int nxmovement = 0;
    unsigned int nymovement = 0;

    unsigned int gledmovement = 0;

    unsigned int control1 = 0;
    unsigned int control2 = 0;
    
    // used for communication
	unsigned char motordata[3] = {0};
	unsigned char pi3_response[1] = {0};

    
    // first, read the motor compressed data,
    read(pi3_socket, motordata, 3);
    
    // uncompress data, extract relavant motor commands,
    nxmovement = (motordata[2] & 0b11000000) >> 6;
    nymovement = (motordata[2] & 0b00110000) >> 4;
    gledmovement = (motordata[2] & 0b00001100) >> 2;

    control1 = motordata[1] & 0b00000011;
    control2 = motordata[2] & 0b00000011;

  
    // pi3 movement execution. 
    if (nxmovement != 3){nxthread = std::thread (nxsetstep, nxmovement);}
    if (nymovement != 3){nythread = std::thread (nysetstep, nymovement);}
    gledsetstate(gledmovement);


    // this is where we must check the control bits. to see if they are a command sequence. 

    if (control1 == 3 && control2 == 3) {
        // shutdown code
        
        nxthread.join();
        nythread.join();
        
        system("sudo shutdown now");
    }
    
    // execute other control functions here. 
    // if (control1 == _ && control2 == _) {}

    
    // then set response,
    pi3_response[0] = 1;

    // finally, write the response to the pi3. 
    write(pi3_socket, pi3_response, 1);

    // close threads.
    nxthread.join();
    nythread.join();

}


#endif
