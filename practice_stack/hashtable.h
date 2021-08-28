/*
 * Name: Tyler McDonald
 * Test 2
 * Purpose: Creating a hash table using array of head pointers.
 */

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include "string"

#define HASHTABLESIZE 15

using std::cout;
using std::endl;
using std::string;

struct Data
{
	int id;
	string data;
};

struct Node
{
	Data data;
	Node *next;
};



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
	bool addNode(int, string *);
	bool deleteNode(int);
	bool getNode(int, Data *);
	int hash(int);
	void printList(bool = false);
	bool clearList();

	Node *hashtable[HASHTABLESIZE];
	int count;
	Node *setUpNode(int, string *);
	Node *head;
};

#endif/*HASHTABLE_HASHTABLE_H*/
