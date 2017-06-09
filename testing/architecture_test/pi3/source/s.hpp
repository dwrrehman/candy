/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : s.hpp
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
// prototype and thread declararation for spinal cord function in pi3.

#ifndef s_dot_hpp
#define s_dot_hpp

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
	unsigned int control2

	);


 	std::thread txflthread;
    std::thread txfrthread;
    std::thread tzflthread;
    std::thread tzfrthread;
    std::thread cflthread;
    std::thread cfrthread;


#endif 

