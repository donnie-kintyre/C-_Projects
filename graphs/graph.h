/*
 * Name: Tyler McDonald
 * Coding Final Project
 * Purpose: Create a graph using two classes, one for the graph object and one
 *          for the edges object.
 */
#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "data.h"

using std::cout;
using std::endl;
using std::vector;
using std::stack;


#define MAX_VERTEX 10

    class BiDirGraph {

public:
    
    //Constructor
    BiDirGraph();

    //Destructor
    ~BiDirGraph();

    //Public Methods
    bool isEmpty();
    int getCountVertex();
    int getEdgeCount();
    bool getVertex(int);
    bool addVertex(int);
    bool deleteEdge(int, int);
    bool deleteVertex(int);
    void displayGraph();
    bool addEdge(int, int, int);
    void DFS();

private:

void DFS_util(int, vector<bool>&);

    int edgeCount;
    int vertexCount;
    
    vector<vector<int>> matrix;
    vector<Vertex> vertices;
};

#endif /*GRAPH_GRAPH_H*/
