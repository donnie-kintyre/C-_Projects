/*
 Name: Tyler McDonald
 Coding 02
 Purpose: Demonstrate the use of classes, objects, and inheritance.
          Also, to understand the difference between tight and loose coupling ADTs.
 */

#include "sphere.h"

Sphere::Sphere() {
    //setters
    setRadius(MIN);
}

Sphere::Sphere(int r) {
    //setters
    setRadius(r);
}

Sphere::~Sphere() {
}


float Sphere::getVolume() {
    //This returns the volume of a circle
    return (4.0/3) * M_PI * radius * radius * radius;
}

float Sphere::getArea() {
    //This returns surface area overriding the getArea() of Circle
    return 4 * M_PI * radius * radius;
}
