/*
 * Name: Tyler McDonald
 * Test 2
 * Purpose: Creating a hash table using array of head pointers.
 */
#include "hashtable.h"

//Constructor
Hashtable::Hashtable()
{
	count = 0;
	for (int i = 0; i < HASHTABLESIZE; i++)
	{
		head = nullptr;
		hashtable[i] = head;
	}
}

//Destructor
Hashtable::~Hashtable()
{
	for (int i = 0; i < HASHTABLESIZE; i++)
	{
		if (hashtable[i])
		{
			clearList(); //this should clear out the list
			delete hashtable[i];	   //this will delete the hashtable entry/ptr
		}
	}
}

//Private Method
int Hashtable::hash(int id)
{
	return id % HASHTABLESIZE;
}

//Public Methods

bool Hashtable::insertEntry(int id, string *info)
{
	bool added = false;
	int position = hash(id);

	if (id > 0 && *info != "")
	{
		if (!hashtable[position])
		{
			hashtable[position] = new Node;
			added = addNode(id, info);
			if (added)
			{
				count++;
			}
		}
		else
		{
			added = addNode(id, info);
			if (added)
			{
				count++;
			}
		}
	}
	return added;
}

string Hashtable::getData(int searchID)
{
	Data info;
	string returnString = "";
	int position = hash(searchID);

	if (count > 0 && searchID > 0)
	{
		if (hashtable[position] && getNode(searchID, &info))
		{
			returnString = info.data;
		}
	}
	return returnString;
}

bool Hashtable::removeEntry(int killID)
{
	bool foundID = false;
	int position = hash(killID);

	if (killID > 0)
	{
		if (hashtable[position] && deleteNode(killID))
		{
			count--;
			foundID = true;
		}
	}
	return foundID;
}

int Hashtable::getCount()
{
	return count;
}

void Hashtable::printTable()
{
	for (int i = 0; i < HASHTABLESIZE; i++)
	{
		if (hashtable[i])
		{
			cout << "Table Entry " << i << ": ";
			printList();
		}
		else
		{
			cout << "Table Entry " << i << ": EMPTY!" << endl;
		}
	}
}

Node *Hashtable::setUpNode(int id, string *info)
{
	Node *setNode = new Node;
	setNode->data.id = id;
	setNode->data.data = *info;
	setNode->next = NULL;
	return setNode;
}

bool Hashtable::addNode(int id, string *info)
{
	Node *current = head;
	bool addedNode = false;
	bool foundDupe = false;

	if (id > 0 && *info != "")
	{

		if (!head)
		{
			//algorithm to add head if list is empty
			head = setUpNode(id, info);
			addedNode = true;
		}

		while (!addedNode && !foundDupe && current)
		{
			if (id == current->data.id)
			{
				foundDupe = true;
			}
			else if (!current->next)
			{
				//algorithm for add tail
				Node *newNode = setUpNode(id, info);
				current->next = newNode;
				addedNode = true;
			} 
			else {
				current = current->next;
			}
		}
	}
	return addedNode;
}

bool Hashtable::deleteNode(int killNode)
{
	Node *current = head;
	bool foundNode = false;

	if (current && killNode == head->data.id && current->next == NULL)
	{
		delete head;
		head = NULL;
		foundNode = true;
	}
	else if (current && killNode == head->data.id)
	{
		head = current->next;
		delete current;
		foundNode = true;
	}

	while (current && !foundNode)
	{
		if (current->next && killNode == current->data.id)
		{
			head->next = current->next;
			delete current;
			foundNode = true;
		}
		else
		{
			current = current->next;
		}
	}
	return foundNode;
}

bool Hashtable::getNode(int searchID, Data *info)
{
	Node *current = head;
	bool foundNode = false;
	info->id = -1;
	info->data = "";

	while (!foundNode && current)
	{

		if (searchID == current->data.id)
		{
			info->id = current->data.id;
			info->data = current->data.data;
			foundNode = true;
		}
		else
		{
			current = current->next;
		}
	}
	return foundNode;
}

void Hashtable::printList(bool backward)
{
	Node *current = head;

	if (!head)
	{
		cout << "EMPTY!" << endl;
	} else {
		while (current)
		{
			if (!current->next)
			{
				cout << current->data.id << endl;
			}
			else
			{
				cout << current->data.id << "-->";
			}
			current = current->next;
		}
	}
}

bool Hashtable::clearList()
{
	Node *current = head;
	bool clearedList = false;

	while (current)
	{
		head = current;
		current = current->next;
		delete head;

		if (!current)
		{
			head = NULL;
			clearedList = true;
		}
	}
	return clearedList;
}
