/*
 Name: Tyler McDonald
 Coding 02
 Purpose: Demonstrate the use of classes, objects, and inheritance.
          Also, to understand the difference between tight and loose coupling ADTs.
 */

#include "main.h"

int main(int argc, char** argv) {

    //creates a circle object with no parameters
    Circle myCircle1;
    //creates a circle object with radius
    Circle myCircle2(10);

    //creates a sphere object with no parameters
    Sphere mySphere1;
    //creates a sphere object with radius
    Sphere mySphere2(10);

    //pass objects by reference
    displayCircle(&myCircle1);
    displayCircle(&myCircle2);

    displaySphere(&mySphere1);
    displaySphere(&mySphere2);

    return 0;
}
