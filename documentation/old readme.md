# candy

**this is the source code for a robot named _candy._**

## build

you can build a main program by executing "make" from the command line, and you can start the program by executing "sudo ./wakeup".

### file structure

the three directories named _pi0_, _pi2_, and _pi3_ all group source code according to what processor it will be running on in the robot. source code in pi3 will be running on a raspberry pi3, code in pi2 will run on a raspberry pi 2, and code in pi0 will run on a raspberry pi zero.

in each directory, there is a _main program_, and a _makefile_ to compile that program. in the pi3 directory, there is an additional file which is used to store HTM data, but ill get to that later. 

### program structure

within each main program, there are four main sections of code:

&nbsp;&nbsp;&nbsp;&nbsp; - constants

&nbsp;&nbsp;&nbsp;&nbsp; - variables

&nbsp;&nbsp;&nbsp;&nbsp; - declerations and functions

&nbsp;&nbsp;&nbsp;&nbsp; - main function

the constants and variables sections hold things like _pin numbers_, _maximum and minumum movement limits_, and _position and state variables_ for motors. these are sometimes used as buffers for the user defined functions in the next section. 

the declarations and functions contains all the methods used in the code besides the main function. this includes the _setstep functions_ (one for each motor controlled by that processor), the _basalganglia function_, the _dorsalrootganglia function_ (only on pi2 and pi3), the _vestibularsystem function_ (only on pi3), and the _neocortex function_ (only on pi3). all of these functions will be talked about in detail in the next section.

the main function holds the _initialization sequence_ and the _main loop_. these will be elaborated in the next section as well. 

### program part descriptions

#### main function

##### initialization sequence

this sequence of startup commands is what is executed in the main function every time the robot wakes up. it entails creating and setting up the sockets that are used to pass sensory and motor information back and forth, testing those sockets by sending dummy bytes back and forth, testing that all the sensors work and are passing data, and finally that all motors are connected properly and are functional by moving each one of them back and forth. there is also an initialization sequence for the vestibularsystem, and the neocortex, but those will be covered later.

##### main loop

the main loop is the meat of the computation the processors are doing. it involves an infinite while loop that contains calls to important functions like the neocortex, or the basalganglia, and the loop continually processes the streaming sensory input and directs it into the functions in the main loop that process it. there is a main loop in every single main program. 

#### declerations and functions

##### setstep function

this function is the lowest level of control the robot has to the motors, as this function involves _timing the firings of each digital output_ so that the stepper motors which the robot controls will turn in the desired way, and at the desired speed.

the function works on a _"frame by frame"_ basis, in other words, the function does not fully take in the desired movement of a particular motor, but rather, it just takes in the _direction_ you want the motor to go in, and it steps that motor by _one step_. through the right number of sucessive calls of the setstep function for a particular motor, you can achieve the _desired position_ of the motor. getting the motor to go at the _desired speed_ involves stepping the motor in the direction you want only after a _set amount of milliseconds_, and it is this millisecond delay that determines the speed that the motor will end up going at. 

there is one more additional option for the input of the setstep function, and that is to make the motor _relax_.

##### basalganglia function

this function deals with _calling all the setstep functions_ and _sending motor data over sockets_ according to what the desired motor movement is at any given time. this function calls every setstep function in a seperate thread (there are at most 6 setstep functions in a particular main program) to avoid waiting for a setstep function to turn a slow motor. for sending motor data over sockets, this involves compressing the desired motor movements into two bytes of information that is sent to all processors that need it. 









this is a test. 








(this unfinished document will be filled with explanations of the source code.) 
