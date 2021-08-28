/*
 * Name: Tyler McDonald
 * Coding 06
 * Purpose: Creating a hash table class/object using a
 *          standard struct type and a linked list.
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
