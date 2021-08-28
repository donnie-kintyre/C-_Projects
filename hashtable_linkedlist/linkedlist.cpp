/*
 * Name: Tyler McDonald
 * Coding 06
 * Purpose: Creating a hash table class/object using a 
 *          standard struct type and a linked list.
 */

#include "linkedlist.h"

//Constructor
LinkedList::LinkedList() {
  head = NULL;
}

//Destructor
LinkedList::~LinkedList() {
  clearList();
}

Node *LinkedList::setUpNode(int id, string *info) {
    Node *setNode = new Node;
    setNode->data.id = id;
    setNode->data.data = *info;
    setNode->prev = NULL;
    setNode->next = NULL;
    return setNode;
}

bool LinkedList::addNode(int id, string *info) {
    Node *current = head;
    bool addedNode = false;
    bool foundDupe = false;

  if (id > 0 && *info != "") {

    if (!head) {
        //algorithm to add head if list is empty
        head = setUpNode (id, info);
        addedNode = true;
    }

    if (id < head->data.id) {
        //algorithm for add head if list is not empty
        Node *newNode = setUpNode(id, info);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        addedNode = true;
    }

    while (!addedNode && !foundDupe && current) {

      if (id == current->data.id) {
          foundDupe = true;

      } else if (id < current->data.id) {
          //algorithm to add node in middle
          Node *newNode = setUpNode(id, info);
          newNode->next = current;
          newNode->prev = current->prev;
          current->prev->next = newNode;
          current->prev = newNode;
          addedNode = true;

      } else if (!current->next) {
          //algorithm to add tail
          Node *newNode = setUpNode(id, info);
          newNode->prev = current;
          current->next = newNode;
          addedNode = true;

      } else {
          current = current->next;
      }
    }
  }
  return addedNode;
}

bool LinkedList::deleteNode(int killNode) {
  Node *current = head;
  bool foundNode = false;

  if (current && killNode == head->data.id && head->next == NULL) {
      delete head;
      head = NULL;
      foundNode = true;
  }

  else if (current && killNode == head->data.id) {
      current->next->prev = NULL;
      head = current->next;
      delete current;
      foundNode = true;
  }

  while (current && !foundNode) {

    if (!current->next && killNode == current->data.id) {
      current->prev->next = NULL;
      delete current;
      foundNode = true;

    } else if (killNode == current->data.id) {
      current->prev->next = current->next;
      current->next->prev = current->prev;
      delete current;
      foundNode = true;

    } else {
      current = current->next;
    }
  }
  return foundNode;
}

bool LinkedList::getNode(int searchID, Data *info) {
  Node *current = head;
  bool foundNode = false;
  info->id = -1;
  info->data = "";

  while (!foundNode && current) {

    if (searchID == current->data.id) {
      info->id = current->data.id;
      info->data = current->data.data;
      foundNode = true;
    } else {
      current = current->next;
    }
  }
  return foundNode;
}

void LinkedList::printList(bool backward) {
  Node *current = head;

  if (!head) {
    cout << "EMPTY!" << endl;
  }

  if (!backward) {
    while(current) {
      if (!current->next) {
        cout << current->data.id << endl;
      } else {
        cout << current->data.id << "-->";
      }
      current = current->next;
    }
  } else {
    current = head;
    bool tail = false;
    while (current && !tail) {
      if (current->next) {
        current = current->next;

      } else {
        tail = true;
      }
    }
    while(current) {
      cout << current->data.id << ": " << current->data.data << endl;
      current = current->prev;
    }
  }
}

int LinkedList::getCount() {
  Node *current = head;
  int count = 0;
  while(current) {
  current = current->next;
  count++;
  }
  return count;
}

bool LinkedList::clearList() {
  Node *current = head;
  bool clearedList = false;

  while (current) {
    head = current;
    current = current->next;
    delete head;

    if (!current) {
      head = NULL;
      clearedList = true;
    }
  }
  return clearedList;
}

bool LinkedList::exists(int searchID) {
  Node *current = head;
  bool foundNode = false;

  while (!foundNode && current) {
    if (searchID == current->data.id && current) {
      foundNode = true;
    } else {
      current = current->next;
    }
  }
  return foundNode;
}
