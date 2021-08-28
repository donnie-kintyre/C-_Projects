/*
 * Name: Tyler McDonald
 * Coding 05
 * Purpose: Goal is to create a fully functional doubly linked list class
 *          and created a linked list object from the linked list class.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "data.h"

using std::cout;
using std::endl;


class LinkedList {


public:
  //Constructor
  LinkedList();

  //Destructor
  ~LinkedList();

  //prototypes to methods
  bool addNode(int, string*);
  bool deleteNode(int);
  bool getNode(int, Data*);
  void printList(bool = false);
  int getCount();
  bool clearList();
  bool exists(int);

private:

  //private helper function
  Node *setUpNode(int, string*);

  Node *head; //a pointer to the first node or NULL if list is empty
};

#endif //LINKEDLIST_H
