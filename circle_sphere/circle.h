/*
 Name: Tyler McDonald
 Coding 02
 Purpose: Demonstrate the use of classes, objects, and inheritance.
          Also, to understand the difference between tight and loose coupling ADTs.
 */


#ifndef CLASSES_CIRCLE_H
#define CLASSES_CIRCLE_H
#define _USE_MATH_DEFINES

#define MIN 0
#include <cmath>

class Circle {

    public:

    //constructors, one will overload
    Circle();
    Circle(int);

    //destructor
    ~Circle();

    //Getters
    float getPi();
    int getRadius();
    float getArea();
  
    //Setters
    void setRadius(int);

protected:
    //private variables that define a circle
    int radius;
};

#endif //CLASSES_CIRCLE_H
