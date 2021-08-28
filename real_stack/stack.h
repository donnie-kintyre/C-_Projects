/*
* Name: Tyler McDonald
* Coding 04
* Purpose: Build a stack object that works with a struct data type.
*          Struct data type except both an int and a string and fills
*          the stack with the struct data using a pointer.
*/

#ifndef STACK_H
#define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"
#define STACK_SIZE 10 // do not modify this define

class Stack {

public:
  //Constructor
  Stack();

  //Destructor
  ~Stack();

  // declaring all the function
  bool push(int, const string&);
  bool pop(Data*);
  bool peek(Data*);
  bool isEmpty();

private:

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H
