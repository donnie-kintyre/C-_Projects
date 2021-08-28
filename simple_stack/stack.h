/*
* Name: Tyler McDonald
* Coding 03
* Purpose: Take a bad stack.cpp and fix it to eliminate all bugs and logical errors.
*          Rid the code of bad practices and create properly structured code.
*          Create a functional stack and test it to ensure it cannot be broken.
*/

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define SIZE 10

class Stack {

  public:
    // Constructor
    Stack();

    // declaring all the function
    bool push(int);
    bool pop(int*);
    bool peek(int*);
    bool isEmpty();

  private:
    int top;
    int a[SIZE];

};

#endif //STACK_STACK_H
