/*
 Name: Tyler McDonald
 Coding 02
 Purpose: Demonstrate the use of classes, objects, and inheritance.
          Also, to understand the difference between tight and loose coupling ADTs.
 */

#include "functions.h"

void displayCircle(Circle *myCircle){

    std::cout << myCircle->getRadius() << std::endl;
    std::cout << myCircle->getPi() << std::endl;
    std::cout << myCircle->getArea() << std::endl;
    std::cout << std::endl;

}

void displaySphere(Sphere *mySphere){

    std::cout << mySphere->getRadius() << std::endl;
    std::cout << mySphere->getPi() << std::endl;
    std::cout << mySphere->getArea() << std::endl;
    std::cout << mySphere->getVolume() << std::endl;
    std::cout << std::endl;

}
