/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : movements.cpp
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
// movement controller variables for all motors and devices on candy.


#ifndef movements_dot_hpp
#define movements_dot_hpp

// ---------------- movement controllers ------------------


unsigned
    txflmovement = 0, // pi3
    txfrmovement = 0,
    tzflmovement = 0,
    tzfrmovement = 0,
    cflmovement = 0,
    cfrmovement = 0,

    txblmovement = 0, // pi2
    txbrmovement = 0,
    tzblmovement = 0,
    tzbrmovement = 0,
    cblmovement = 0,
    cbrmovement = 0,

    nxmovement = 0, // pi0
    nymovement = 0,

    wled = 0, // pi2
    gled = 0, // pi0

    control1 = 0, // pi2/0
    control2 = 0; // pi2/0

#endif  
    