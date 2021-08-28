/*
 * Name: Tyler McDonald
 * Test 1
 * Purpose: Create a FIFO Queue using Linked Lists
 */

 #include "fifo.h"


 //Constructor
 Fifo::Fifo() {
   head = NULL;
 }

 Fifo::~Fifo() {}


 // Public methods

 bool Fifo::isEmpty() {
   return head == NULL;
 }

 bool Fifo::pull(Data *empty_struct) {
   Node *current = head;
   bool foundNode = false;
   empty_struct->id = -1;
   empty_struct->data = "";

   while (current && !foundNode) {
     if (current && head->next == NULL) {
         empty_struct->id = head->data.id;
         empty_struct->data = head->data.data;
         delete head;
         head = NULL;
        foundNode = true;
     }
     else {
         current->next->prev = NULL;
         head = current->next;
         empty_struct->id = current->data.id;
         empty_struct->data = current->data.data;
         delete current;
         foundNode = true;
     }
   }
   return foundNode;
 }

 bool Fifo::peek(Data *empty_struct) {
   Node *current = head;
   bool foundNode = false;
   empty_struct->id = -1;
  empty_struct->data = "";

   while (!foundNode && current) {
     empty_struct->id = current->data.id;
     empty_struct->data = current->data.data;
     foundNode = true;
   }
   return foundNode;
 }

 bool Fifo::push(int id, const string &info) {
     Node *current = head;
     bool addedNode = false;
     bool foundDupe = false;

   if (id > 0 && info != "") {

     if (current == NULL) {
        //algorithm to add head if list is empty
        head = setUpNode(id, info);
        addedNode = true;
     }

     while (!addedNode && !foundDupe && current) {
       if (id == current->data.id) {
         foundDupe = true;
       } else {
         //algorithm for add tail
         Node *newNode = setUpNode(id, info);
         newNode->prev = current;
         current->next = newNode;
         addedNode = true;
       }
     }
   }
   return addedNode;
 }

 //Private method
 Node *Fifo::setUpNode(int id, const string &info) {
     Node *setNode = new Node;
     setNode->data.id = id;
     setNode->data.data = info;
     setNode->prev = NULL;
     setNode->next = NULL;
     return setNode;
 }
