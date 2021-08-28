/*
* Name: Tyler McDonald
* Coding 03
* Purpose: Take a bad stack.cpp and fix it to eliminate all bugs and logical errors.
*          Rid the code of bad practices and create properly structured code.
*          Create a functional stack and test it to ensure it cannot be broken.
*/

#include "stack.h"

//Constructor
Stack::Stack() {
  top = -1;
}

//push method to add an element to the stack.
//if the stack is full, it will return false.
bool Stack::push(int x) {
  bool rslt = true;
  if(top >= SIZE-1)
  {
    rslt = false;
  } else {
    a[++top] = x;
  }
  return rslt;
}

//pop method to decrement top if found true.
//if the stack is empty, pop will return false.
bool Stack::pop(int *y) {
  bool rslt = true;
  if(top < 0) {
    rslt = false;
  } else {
    *y = a[top--];
  }
  return rslt;
}

//peek method will return the element where top is located
//in the stack. If the stack is empty, peek will return false.
bool Stack::peek (int *z) {
  bool rslt = false;
  if (top > -1) {
    *z = a[top];
    rslt = true;
  }
  return rslt;
}

// function to check if stack is empty
bool Stack::isEmpty() {
  return top < 0;
}
