/*
 * Name: Tyler McDonald
 * Coding 06
 * Purpose: Creating a hash table class/object using a
 *          standard struct type and a linked list.
 */

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include "linkedlist.h"
#include "data.h"

#define HASHTABLESIZE 15

using std::cout;
using std::endl;

class Hashtable {

public:
	//Constructor
	Hashtable();

	//Destructor
	~Hashtable();

	bool insertEntry(int, string*);
	string getData(int);
	bool removeEntry(int);
	int getCount();
	void printTable();

private:
	int hash(int);

	LinkedList *hashtable[HASHTABLESIZE];
	int count;
};

#endif/*HASHTABLE_HASHTABLE_H*/
