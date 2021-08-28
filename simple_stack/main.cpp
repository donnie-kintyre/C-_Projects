/*
* Name: Tyler McDonald
* Coding 03
* Purpose: Take a bad stack.cpp and fix it to eliminate all bugs and logical errors.
*          Rid the code of bad practices and create properly structured code.
*          Create a functional stack and test it to ensure it cannot be broken.
*/

#include "main.h"

int main(int argc, char** argv) {

  //generic integer to pass in pop() and peek()
  int num = 77;
  //Class
  Stack s1;

  //test to randomly call push, pop, and peek
  srand(time(NULL));

  for (int i=0; i < SIZE*10; i++) {
    int num_rand = rand() % 3;

    if (num_rand == 0) {
      std::cout << s1.pop(&num) << std::endl;
      std::cout << "We Poppin'" << std::endl;
    } else if (num_rand == 1) {
        std::cout << s1.push(i) << std::endl;
        std::cout << "We Pushin'" << std::endl;
    } else {
      std::cout << s1.peek(&num) << std::endl;
      std::cout << "We Peekin'" << std::endl;
    }
  }

  //Check if the stack is empty.
  if (!s1.isEmpty()) {
    std::cout << "Stack is not empty!" << std::endl;
  } else {
    std::cout << "Stack is empty!" << std::endl;
  }

  std::cout << "" << std::endl;

  //for loop to create overflow in push() method.
  for (int i=0; i < SIZE*10; i++) {
    std::cout << i << std::endl;
    std::cout << s1.peek(&num) << std::endl;
    if (!s1.push(i)) {
      std::cout << "Overflow" << std::endl;
    }
  }

  //Check if the stack is empty.
  if (!s1.isEmpty()) {
    std::cout << "Stack is not empty!" << std::endl;
  } else {
    std::cout << "Stack is empty!" << std::endl;
  }

  std::cout << "" << std::endl;

  //for loop to create underflow in pop() method.
  for (int i=0; i < SIZE*10; i++) {
    std::cout << i << std::endl;
    std::cout << s1.peek(&num) << std::endl;
    if (!s1.pop(&num)) {
      std::cout << "underflow" << std::endl;
    }
  }

  //Check if the stack is empty.
  if (!s1.isEmpty()) {
    std::cout << "Stack is not empty!" << std::endl;
  } else {
    std::cout << "Stack is empty!" << std::endl;
  }

  std::cout << "" << std::endl;

  //for loop to test underflow in peek() method.
  for (int i=0; i < SIZE*10; i++) {
    std::cout << i << std::endl;
    if (!s1.peek(&num)) {
      std::cout << "underflow" << std::endl;
    }
  }

  //Check if the stack is empty.
  if (!s1.isEmpty()) {
    std::cout << "Stack is not empty!" << std::endl;
  } else {
    std::cout << "Stack is empty!" << std::endl;
  }

  return 0;
}
