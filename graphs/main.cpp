/*
 * Name: Tyler McDonald
 * Coding Final Project
 * Purpose: Create a graph using two classes, one for the graph object and one
 *          for the edges object.
 */

#include "main.h"

int main () {

// create adjacency matrix/graph object
BiDirGraph graph;

//seed for random number generation
srand(time(NULL));


//check if the graph/matrix is empty
if(graph.isEmpty())
{
    cout << "List is empty!" << endl;
} 
else
{
    cout << "List is NOT empty!" << endl;
}
cout << endl;

//Check vertex count
cout << "The Vertex count is: " << graph.getCountVertex() << endl;
cout << endl;

//Check Edge count
cout << "The Edge count is: " << graph.getEdgeCount() << endl;
cout << endl;

//create a 10x10 matrix
for (int i = 0; i < MAX_VERTEX; i++)
{
    if(graph.addVertex(i)) 
    {
        cout << "Added a Vertex!" << endl;
    } 
    else 
    {
        cout << "FAIL! Did not add a vertex!" << endl;
    }
}

cout << endl;

//send an ID and locate the vertex if it exists
for (int i = 0; i < MAX_VERTEX; i++)
{
    int rand_id = (rand() % 20) + 1;
    if (graph.getVertex(rand_id))
    {
        cout << "Successfully found Vertex" << endl;
    }
    else 
    {
        cout <<"Fail! Didn't find Vertex" << endl;
    }
}

cout << endl;

//check if the graph/matrix is empty
if (graph.isEmpty())
{
    cout << "List is empty!" << endl;
}
else
{
    cout << "List is NOT empty!" << endl;
}
cout << endl;

//Check vertex count
cout << "The Vertex count is: " << graph.getCountVertex() << endl;
cout << endl;

//display the matrix
graph.displayGraph();
cout << endl;


//Add edges to the matrix

//generate a random weight
int rand_wt = (rand() % 25) + 1;


//next 3 if statements connects first 3 vertices
if(graph.addEdge(0, 1, rand_wt))
{
    cout << "Added and Edge!" << endl;
}
else 
{
    cout << "FAIL! Did not add an Edge!" << endl;
}

if (graph.addEdge(0, 2, rand_wt * 2))
{
    cout << "Added and Edge!" << endl;
}
else
{
    cout << "FAIL! Did not add an Edge!" << endl;
}

if (graph.addEdge(0, 3, rand_wt * 3))
{
    cout << "Added and Edge!" << endl;
}
else
{
    cout << "FAIL! Did not add an Edge!" << endl;
}

if (graph.addEdge(1, 2, rand_wt * 4))
{
    cout << "Added and Edge!" << endl;
}
else
{
    cout << "FAIL! Did not add an Edge!" << endl;
}

if (graph.addEdge(1, 3, rand_wt * 5))
{
    cout << "Added and Edge!" << endl;
}
else
{
    cout << "FAIL! Did not add an Edge!" << endl;
}

if (graph.addEdge(2, 3, rand_wt * 6))
{
    cout << "Added and Edge!" << endl;
}
else
{
    cout << "FAIL! Did not add an Edge!" << endl;
}

if (graph.addEdge(2, 4, rand_wt * 7))
{
    cout << "Added and Edge!" << endl;
}
else
{
    cout << "FAIL! Did not add an Edge!" << endl;
}

cout << endl;

cout << "The Edge count is: " << graph.getEdgeCount() << endl;
cout << endl;

//display the matrix
graph.displayGraph();
cout << endl;

//delete a few edges
cout << "Deleting a few Edges" << endl << endl;

for (int i = 0; i < MAX_VERTEX - 7; i++)
{
    if (graph.deleteEdge(i, i + 1))
    {
        cout << "Deleted and Edge!" << endl;
    }
    else
    {
        cout << "FAIL! Did not delete an Edge!" << endl;
    }
}

cout << endl;

cout << "The Edge count is: " << graph.getEdgeCount() << endl;
cout << endl;

//display the matrix
graph.displayGraph();
cout << endl;

//Call DFS after vertices and edges have been deleted
cout << "Depth First Search" << endl;
graph.DFS();
cout << endl;
cout << endl;

for (int i = 0; i < MAX_VERTEX - 6; i++)
{
    if(graph.deleteVertex(i)) {
        cout << "Successfully Deleted a Vertex!" << endl;
    }
    else
    {
        cout << "FAIL! Did not delete a Vertex!" << endl;
    }
}
cout << endl;

//Check vertex count
cout << "The Vertex count is: " << graph.getCountVertex() << endl;
cout << endl;

//display the matrix
graph.displayGraph();



return 0;
}