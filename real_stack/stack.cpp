/*
* Name: Tyler McDonald
* Coding 04
* Purpose: Build a stack object that works with a struct data type.
*          Struct data type except both an int and a string and fills
*          the stack with the struct data using a pointer.
*/

// each cpp includes ONLY it's header directly!
#include "stack.h"

//Constructor
Stack::Stack() {
  top = -1;
}

//Destructor
Stack::~Stack() {
  for (int i = 0; i < top; i++) {
    delete stack[i];
  }
}

//push method to add an element to the stack.
//if the stack is full, it will return false.
bool Stack::push(int idInput, const string &strInput) {
  bool pushed = false;
  if(top < STACK_SIZE -1 && idInput >= 0 && strInput != "") {
    Data *newStruct = new Data;
    newStruct->id = idInput;
    newStruct->information = strInput;
    stack[++top] = newStruct;
    pushed = true;
  }
  return pushed;
}

//pop method to decrement top if found true.
//if the stack is empty, pop will return false.
bool Stack::pop(Data *empty_struct) {
  bool popped = false;
  empty_struct->id = -1;
  empty_struct->information = "";

  if(top > -1) {
    empty_struct->id = stack[top]->id;
    empty_struct->information = stack[top]->information;
    delete stack[top];
	   top--;
    popped = true;
  }
  return popped;
}

//peek method will return the element where top is located
//in the stack. If the stack is empty, peek will return false.
bool Stack::peek (Data *empty_struct) {
  bool peeked = false;
  empty_struct->id = -1;
  empty_struct->information = "";

  if (top > -1) {
    empty_struct->id = stack[top]->id;
    empty_struct->information = stack[top]->information;
    peeked = true;
  }
  return peeked;
}

// function to check if stack is empty
bool Stack::isEmpty() {
  return top < 0;
}
