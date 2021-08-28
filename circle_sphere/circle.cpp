/*
 Name: Tyler McDonald
 Coding 02
 Purpose: Demonstrate the use of classes, objects, and inheritance.
          Also, to understand the difference between tight and loose coupling ADTs.
 */

#include "circle.h"

Circle::Circle() {
    //setters
    setRadius(MIN);
}

Circle::Circle(int r) {
    //setters
    setRadius(r);
}

Circle::~Circle() {
}


int Circle::getRadius() {
    return radius;
}

float Circle::getPi() {
    return M_PI;
}

float Circle::getArea() {
    return M_PI * radius * radius;
}


void Circle::setRadius(int r) {
    //protecting setters from being put into an invalid state
    if (r > MIN) {
        radius = r;
    } else {
        radius = MIN;
    }
}
