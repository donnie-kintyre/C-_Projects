/*
 * Name: Tyler McDonald
 * Coding 07
 * Purpose: Creating a Binary Search Tree object that works on struct Data type.
 */

#include "bintree.h"

//Constructor
BinTree::BinTree() {
    count = 0;
    root = NULL;
}

//Destructor
BinTree::~BinTree() {
    clear();
}

//Public Methods

//Check to see if the tree is empty or not

bool BinTree::isEmpty() {
    bool not_empty = false;

    if (root != NULL) {
        not_empty = true;
    }
    return not_empty;
}

//Retrieve the total Nodes in the tree

int BinTree::getCount() {
    return count;
}

//Retrieve the data stored in root

bool BinTree::getRootData(Data *info) {
    info->id = -1;
    info->information = "";
    bool foundNode = false;

    if (root) {
        info->id = root->data.id;
        info->information = root->data.information;
        foundNode = true;
    } 
    return foundNode;
}

/*Display what is in the tree whether it is empty or not.
  Call all three traverse methods inside this method*/

void BinTree::displayTree() {
    cout << "DISPLAY TREE" << endl;
    cout << "==============================================" << endl;

    if (!isEmpty()) {
        cout << "Tree is Empty" << endl;
        cout << "Height: " << getHeight() << endl;
        cout << "Node Count: " << getCount() << endl;
        cout << endl;
        cout << "Pre-Order Traversal" << endl;
        displayPreOrder();
        cout << endl;
        cout << "In-Order Traversal" << endl;
        displayInOrder();
        cout << endl;
        cout << "Post-Order Traversal" << endl;
        displayPostOrder();
        cout << "==============================================" << endl;
        cout << endl;
    } else {
        cout << "Tree is NOT empty" << endl;
        cout << "Height: " << getHeight() << endl;
        cout << "Node Count: " << getCount() << endl;
        cout << endl;
        cout << "Pre-Order Traversal" << endl;
        displayPreOrder();
        cout << endl;
        cout << "In-Order Traversal" << endl;
        displayInOrder();
        cout << endl;
        cout << "Post-Order Traversal" << endl;
        displayPostOrder();
        cout << "==============================================" << endl;
        cout << endl;
    }
}

//clear the tree and set root to NULL once cleared
void BinTree::clear() {
    clear(root);
    root = NULL;
}

//add a node to the tree if data is valid
bool BinTree::addNode(int id, const string *str) {
    bool added = false;

    if ( id > 0 && *str != "") {
        DataNode *newNode = new DataNode;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->data.id = id;
        newNode->data.information = *str;
        added = addNode(newNode, &root);
    }
    return added;
}

//search for the passed ID and remove the node if found
bool BinTree::removeNode(int killID) {
    int tempCount = count;
    bool deletedNode = false;

    if (killID > 0 && root) {
        root = removeNode(killID, root);
    }
    if (count < tempCount) {
        deletedNode = true;
    }
    return deletedNode;
}

//Search for the passed ID and return true if found
bool BinTree::getNode(Data *info, int searchID) {
    bool foundNode = false;

    if (searchID > 0 && root) {
        foundNode = getNode(info, searchID, root);
    }
    return foundNode;
}

//Search for the passed Id and return true if it exists
bool BinTree::contains(int searchID) {
    bool foundNode = false;

    if (searchID > 0 && root) {
        foundNode = contains(searchID, root);
    }
    return foundNode;
}

//Recurse getHeight method to calculate total height of tree dynamically
int BinTree::getHeight() {
    return getHeight(root);
}

//Recurse to print nodes in tree in Pre-Order
void BinTree::displayPreOrder() {
    displayPreOrder(root);
}

//Recurse to print nodes in tree in Post-Order
void BinTree::displayPostOrder() {
    displayPostOrder(root);
}

//Recurse to print nodes in tree In Order
void BinTree::displayInOrder() {
    displayInOrder(root);
}


//Private Methods OVERLOAD

//Private Clear Method that clears all branches
void BinTree::clear(DataNode *subRoot) {
    if (subRoot != NULL) {
        clear(subRoot->left);
        clear(subRoot->right);
        subRoot->left = NULL;
        subRoot->right = NULL;
        delete subRoot;
        count--;
    }
    return;
}

//Private addNode method to recurse and add nodes to tree
bool BinTree::addNode(DataNode *newNode, DataNode **subRoot) {
    bool added = false;

    if (!(*subRoot)) {
        *subRoot = newNode;
        added = true;
        count++;
    } else {
        if (newNode->data.id < (*subRoot)->data.id) {
            added = addNode(newNode, &(*subRoot)->left);
        }
        if (newNode->data.id > (*subRoot)->data.id) {
            added = addNode(newNode, &(*subRoot)->right);
        }
    }
    return added;
}

//Private removeNode method to search and delete nodes
DataNode *BinTree::removeNode(int killID, DataNode *subRoot) {

    if (subRoot) {

        if (killID < subRoot->data.id) {
            subRoot->left = removeNode(killID, subRoot->left);
        } else if (killID > subRoot->data.id) {
            subRoot->right = removeNode(killID, subRoot->right);
        } else {
            DataNode *tempRoot = new DataNode;

            if (subRoot->left == NULL) {
                tempRoot = subRoot->right;
                delete subRoot;
                subRoot = tempRoot;
                count--;
            } else if (subRoot->right == NULL) {
                tempRoot = subRoot->left;
                delete subRoot;
                subRoot = tempRoot;
                count--;
            } else {
                tempRoot = minValueNode(subRoot->right);
                subRoot->data.id = tempRoot->data.id;
                subRoot->data.information = tempRoot->data.information;
                subRoot->right = removeNode(tempRoot->data.id, subRoot->right);
            }
        }
    }
    return subRoot;
}

//Private method used inside removeNode to find the in order successor
DataNode *BinTree::minValueNode(DataNode *node) {
    DataNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

//Private getNode method that will search passed ID and set Data
bool BinTree::getNode(Data *info, int searchID, DataNode *subRoot) {
    bool foundNode = false;

    if (subRoot != NULL) {
        if (searchID == subRoot->data.id) {
            info->id = subRoot->data.id;
            info->information = subRoot->data.information;
            foundNode = true;
        } else {
            if (searchID < subRoot->data.id) {
                foundNode = getNode(info, searchID, subRoot->left);
            }
            if (searchID > subRoot->data.id) {
                foundNode = getNode(info, searchID, subRoot->right);
            }
        }
    }
    return foundNode;
}

//Private Contains method to check if passed ID exists
bool BinTree::contains(int searchID, DataNode *subRoot) {
    bool foundNode = false;

    if (subRoot != NULL) {
        if (searchID == subRoot->data.id) {
            foundNode = true;
        } else {
            if (searchID < subRoot->data.id) {
                foundNode = contains(searchID, subRoot->left);
            }
            if (searchID > subRoot->data.id) {
                foundNode = contains(searchID, subRoot->right);
            }
        }
    }
    return foundNode;
}

//Private getHeight method will dynamically calculate height of tree
int BinTree::getHeight(DataNode *subRoot) {
    int hLeft = 0;
    int hRight = 0;

    if (subRoot) {
        hLeft = getHeight(subRoot->left);
        hRight = getHeight(subRoot->right);
    }
    return subRoot ? 1 + std::max(hLeft, hRight) : 0;
}

//Private method to display tree in Pre-Order
void BinTree::displayPreOrder(DataNode *subRoot) {
    if (subRoot) {
        cout << subRoot->data.id << " " << subRoot->data.information << endl;
        if (subRoot->left) {
            displayPreOrder(subRoot->left);
        }
        if (subRoot->right) {
            displayPreOrder(subRoot->right);
        }   
    }
    return;
}

//Private method to display tree in Post-Order
void BinTree::displayPostOrder(DataNode *subRoot) {
    if (subRoot) {
        if (subRoot->left) {
            displayPostOrder(subRoot->left);
        }
        if (subRoot->right) {
            displayPostOrder(subRoot->right);
        }
        cout << subRoot->data.id << " " << subRoot->data.information << endl;
    }
    return;
}

//Private method to display tree in In Order
void BinTree::displayInOrder(DataNode *subRoot) {
    if (subRoot) {
        if (subRoot->left) {
            displayInOrder(subRoot->left);
        }
        cout << subRoot->data.id << " " << subRoot->data.information << endl;
        if (subRoot->right) {
            displayInOrder(subRoot->right);
        }
    }
    return;
}
