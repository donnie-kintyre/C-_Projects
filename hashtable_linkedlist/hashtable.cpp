/*
 * Name: Tyler McDonald
 * Coding 06
 * Purpose: Creating a hash table class/object using a
 *          standard struct type and a linked list.
 */

#include "hashtable.h"

//Constructor
Hashtable::Hashtable() {
	count = 0;
	for (int i = 0; i < HASHTABLESIZE; i++) {
		hashtable[i] = nullptr;
	}
}

//Destructor
Hashtable::~Hashtable() {
	for (int i = 0; i < HASHTABLESIZE; i++) {
		if (hashtable[i]) {
			hashtable[i]->clearList(); //this should clear out the list
			delete hashtable[i]; //this will delete the hashtable entry/ptr
		}
	}
}

//Private Method
int Hashtable::hash(int id) {
	return id % HASHTABLESIZE;
}


//Public Methods

bool Hashtable::insertEntry(int id, string *info) {
	bool added = false;
	int position = hash(id);

	if (id > 0 && *info != "") {
		if (!hashtable[position]) {
			hashtable[position] = new LinkedList;
			added = hashtable[position]->addNode(id, info);
			if (added) {
				count++;
			}
		} else {
			added = hashtable[position]->addNode(id, info);
			if (added) {
				count++;
			}
		}
	}
	return added;
}

string Hashtable::getData(int searchID) {
	Data info;
	string returnString = "";
	int position = hash(searchID);

	if (count > 0 && searchID > 0) {
		if (hashtable[position] && hashtable[position]->getNode(searchID, &info)) {
			returnString = info.data;	
		}
	}
	return returnString;
}

bool Hashtable::removeEntry(int killID) {
	bool foundID = false;
	int position = hash(killID);

	if (killID > 0) {
		if (hashtable[position] && hashtable[position]->deleteNode(killID)) {
			count--;
			foundID = true;
		}	
	}
	return foundID;
}

int Hashtable::getCount() {
	return count;
}

void Hashtable::printTable() {
	for (int i = 0; i < HASHTABLESIZE; i++) {
		if (hashtable[i]) {
			cout << "Table Entry " << i << ": ";
			hashtable[i]->printList();
		} else {
			cout << "Table Entry " << i << ": EMPTY!" << endl;
		}
	}
}
