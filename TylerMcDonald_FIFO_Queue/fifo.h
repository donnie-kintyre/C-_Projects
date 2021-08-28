/*
 * Name: Tyler McDonald
 * Test 1
 * Purpose: Create a FIFO Queue using Linked Lists
 */

 #ifndef FIFO_H
 #define FIFO_H

 #include "string"

 using std::string;

 struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

 class Fifo {

 public:
   //Constructor
   Fifo();

   //Destructor
   ~Fifo();

   //prototypes to methods
   bool push(int, const string&);
   bool pull(Data*);
   bool peek(Data*);
   bool isEmpty();

 private:

   //private helper function
   Node *setUpNode(int, const string &info);
   Node *head; //a pointer to the first node or NULL if list is empty
 };

 #endif //FIFO_H
