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
// spinal cord function for pi3. 
// takes in the desired motor movement, and executes that movement in a thread. 
// it also takes in a socket, and writes the pi2/0 data and receives an ackknownledgement.

#ifndef s_dot_cpp
#define s_dot_cpp

// -------------- includes ---------------

// system includes
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

//my includes

#include "s.hpp" 

// motor neurons:
#include "txfl.cpp"
#include "tzfl.cpp"
#include "cfl.cpp"

#include "txfr.cpp"
#include "tzfr.cpp"
#include "cfr.cpp"


void spinalcord(

	int pi2_socket, 
	int pi0_socket,

	unsigned int txflmovement,
	unsigned int tzflmovement,
	unsigned int cflmovement,

	unsigned int txfrmovement,
	unsigned int tzfrmovement,
	unsigned int cfrmovement,

	unsigned int txblmovement,
	unsigned int tzblmovement,
	unsigned int cblmovement,

	unsigned int txbrmovement,
	unsigned int tzbrmovement,
	unsigned int cbrmovement,

	unsigned int nxmovement,
	unsigned int nymovement,

	unsigned int wledmovement,
	unsigned int gledmovement,

	unsigned int control1,
	unsigned int control

	){

	unsigned char motordata[3] = {0};
	unsigned char pi0_response[1] = {0};
	unsigned char pi2_response[1] = {0};

    
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

    // pass to other computers:

    // first, write
    write(pi2_socket, motordata, 3);
    write(pi0_socket, motordata, 3);

    // then, clear responses,
    pi0_response[0] = 0;
    pi2_response[0] = 0;

    // finally, read the responses.
    read(pi2_socket, pi2_response,1);
    read(pi0_socket, pi0_response,1);

    if (pi0_response[0] != 1 || pi2_response[0] != 1) {
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


#endif