/*
 * Name: Tyler McDonald
 * Coding 07
 * Purpose: Creating a Binary Search Tree object that works on struct Data type.
 */

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <iostream>
#include "data.h"

using std::cout;
using std::endl;


class BinTree {

public:
    //Constructor
    BinTree();

    //Destructor
    ~BinTree();

    //public methods
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);
    void displayTree();

    //public methods with a private overload
    void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:

    //private methods to overload above methods. Recursion
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);

    //min value node method to use  removeNode to get inOrder successor
    DataNode* minValueNode(DataNode*);

    //private attributes
    int count;
    DataNode *root;
    
};



#endif /* BINTREE_BINTREE_H */

