/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : states.hpp
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
// states of the controller variables for all motors and devices on candy.


#ifndef states_dot_hpp
#define states_dot_hpp

// ---------------- state controllers ------------------


unsigned
    txflstate = 0, // pi3
    txfrstate = 0,
    tzflstate = 0,
    tzfrstate = 0,
    cflstate = 0,
    cfrstate = 0,

    txblstate = 0, // pi2
    txbrstate = 0,
    tzblstate = 0,
    tzbrstate = 0,
    cblstate = 0,
    cbrstate = 0,

    nxstate = 0, // pi0
    nystate = 0,

    wledstate = 0, // pi2
    gledstate = 0; // pi0




// position vairables

unsigned
    txflposition = 0, // pi3
    txfrposition = 0,
    tzflposition = 0,
    tzfrposition = 0,
    cflposition = 0,
    cfrposition = 0,

    txblposition = 0, // pi2
    txbrposition = 0,
    tzblposition = 0,
    tzbrposition = 0,
    cblposition = 0,
    cbrposition = 0,

    nxposition = 0, // pi0
    nyposition = 0;


#endif  
    