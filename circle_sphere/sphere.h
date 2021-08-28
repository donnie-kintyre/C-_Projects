/*
 Name: Tyler McDonald
 Coding 02
 Purpose: Demonstrate the use of classes, objects, and inheritance.
          Also, to understand the difference between tight and loose coupling ADTs.
 */


#ifndef CLASSES_SPHERE_H
#define CLASSES_SPHERE_H

#include "circle.h"

class Sphere : public Circle {
public:
    Sphere();
    Sphere(int);
    ~Sphere();

    /*
     * Getters
     */
    float getVolume();
    float getArea();
};
#endif //CLASSES_SPHERE_H
