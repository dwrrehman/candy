/// ----------- candy -------------
/*
 *   project : architecture_test
 *   file : main3.cpp
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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <wiringPi.h>

// my includes:

// constants:
#include "pins.hpp"
#include "movements.hpp"
#include "states.hpp"

// spinal cord:
#include "s.cpp"



// --------------------- parameters -------------------------


int portno2 = 6001;
int portno0 = 6002;

bool willshutdown = false;



// ---------------- main code -------------------------

int main(void) {

    // intro
    std::cout << "candy - pi3\n" << "this is a test of sockets, the motor protocol, finished spinal cord, and using motor neuron functions.\n";

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

    

    unsigned char motor_data[3];
    unsigned char camera_response[1];

    int motor_socket2, motor_socket0, camera_socket2;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;     
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno2);
    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    motor_socket2 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    printf("motor_socket2: %d\n", motor_socket2);
    camera_socket2 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    printf("camera_socket2: %d\n", camera_socket2);
  
     
    if (motor_socket2 < 0 || camera_socket2 < 0) {
        printf("a pi3 accept: a pi2 connection failure.\n"); 
        printf("pi2: %d, pi2camera: %d\n", motor_socket2, camera_socket2);
        exit(1);
    } 
    else {
        printf("pi2 connected.\n");

        socklen_t clilen;
        struct sockaddr_in serv_addr, cli_addr;     
        printf("1motor_socket0: %d\n", motor_socket0);
        int sockfd0 = socket(AF_INET, SOCK_STREAM, 0);
        printf("2motor_socket0: %d\n", motor_socket0);
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno0);
        printf("3motor_socket0: %d\n", motor_socket0);

        bind(sockfd0, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
        printf("4motor_socket0: %d\n", motor_socket0);
        listen(sockfd0, 5);
        printf("5motor_socket0: %d\n", motor_socket0);
        clilen = sizeof(cli_addr);



        motor_socket0 = accept(sockfd0, (struct sockaddr *) &cli_addr, &clilen);
        printf("motor_socket0: %d\n", motor_socket0);
    
        if (motor_socket0 < 0) {
            printf("a pi3 accept: a pi0 connection failure.\n"); 
            printf("pi0: %d\n", motor_socket0);
            exit(1);
        } 
        else {
            printf("pi0 connected.\n");
        }
    }


   // testconnection();
    

    
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
    std::cout << "\t16 : gled\n";

    std::cout << "\t17 : control1\n";
    std::cout << "\t18 : control2\n\n";

    std::cout << "input the desired controller to move: ";
    std::cin >> desiredmotor;


    std::cout << "\t0 : relaxed/off\n";
    std::cout << "\t1 : forwards/on\n";
    std::cout << "\t2 : backwards\n";
    std::cout << "\t3 : hold\n\n";

    std::cout << "input the desired data: ";
    std::cin >> direction;

    std::cout << "input the delay in milliseconds: ";
    std::cin >> givendelay;

    std::cout << "input the number of steps: ";
    std::cin >> givensteps;

    std::cout << "thank you.\n\n";


    // exectution:



    if (desiredmotor == 1) {
        txflmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        txflmovement = 0;
    }

    else if (desiredmotor == 2) {
        tzflmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        tzflmovement = 0;
    }
    
    else if (desiredmotor == 3) {
        cflmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        cflmovement = 0;
    }




    
    else if (desiredmotor == 4) {
        txfrmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        txfrmovement = 0;
    }
    
    else if (desiredmotor == 5) {
        tzfrmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        tzfrmovement = 0;
    }
    
    else if (desiredmotor == 6) {
        cfrmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        cfrmovement = 0;
    }




    
    else if (desiredmotor == 7) {
        txblmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        txblmovement = 0;
    }
    
    else if (desiredmotor == 8) {
        tzblmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        tzblmovement = 0;
    }
    
    else if (desiredmotor == 9) {
        cblmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        cblmovement = 0;
    }
    




    else if (desiredmotor == 10) {
        txbrmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        txbrmovement = 0;
    }
    
    else if (desiredmotor == 11) {
        tzbrmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        tzbrmovement = 0;
    }
    
    else if (desiredmotor == 12) {
        cbrmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        cbrmovement = 0;
    }



    
    else if (desiredmotor == 13) {
        nxmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        nxmovement = 0;
    }
    
    else if (desiredmotor == 14) {
        nymovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        nymovement = 0;
    }



    
    else if (desiredmotor == 15) {
        wledmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        wledmovement = 0;
    }
    
    else if (desiredmotor == 16) {
        gledmovement = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        gledmovement = 0;
    }
    
    else if (desiredmotor == 17) {
        control1 = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        control1 = 0;
    }
    
    else if (desiredmotor == 18) {
        control2 = direction;
        for(int i = 0; i < givensteps; i++) {spinalcord(motor_socket2, motor_socket0, txflmovement, tzflmovement, cflmovement, txfrmovement, tzfrmovement, cfrmovement, txblmovement, tzblmovement, cblmovement, txbrmovement, tzbrmovement, cbrmovement, nxmovement, nymovement, wledmovement, gledmovement, control1, control2); delay(givendelay);}
        control2 = 0;
    }
    
    else if (desiredmotor == 0) {
        printf("exiting...\n");
    }
    

    else {
        std::cout << "error in inputting controller name.\n";
        break;
    }   
}// while(not exiting)



if (willshutdown) {
    memset(motor_data,0,3); // clear previous data 
    motor_data[1] = 3; // set control command sequence: "SHUTDOWN";
    motor_data[2] = 3;

    write(motor_socket2, motor_data, 3);  // pass over data 
    write(motor_socket0, motor_data, 3);  // pass over data 
    system("sudo shutdow now");
}

return 0;}







