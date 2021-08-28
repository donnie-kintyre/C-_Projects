/*
 * Name: Tyler McDonald
 * Coding Final Project
 * Purpose: Create a graph using two classes, one for the graph object and one
 *          for the edges object.
 */

#include "graph.h" 

//Constructor
BiDirGraph::BiDirGraph() {
    vertexCount = 0;
    edgeCount = 0;
}

//Destructor
BiDirGraph::~BiDirGraph() 
{
    matrix.clear();
    vertices.clear();

}

//Graph Methods Public

bool BiDirGraph::isEmpty()
{
    return vertexCount < 1;
}


//Adds vertices to matrix and an id to vertices vector
bool BiDirGraph::addVertex(int id) 
{
    vertexCount++;
    bool addedVertex = false;

    Vertex v_id;
    v_id.id = id;
    vertices.push_back(v_id);

    for (int i = 0; i < vertexCount; i++)
    {
        matrix.resize(vertexCount);
        for (int j = 0; j < vertexCount; j++)
        {
            matrix[i].resize(j);
            matrix[i].push_back(0);
        }
        addedVertex = true;
    }
    return addedVertex;
}


//Displays the matrix
void BiDirGraph::displayGraph() 
{
    cout << "\n\n Adjacency Matrix:" << endl;

    for (int i = 0; i < matrix.size(); ++i)
    {
        cout << "\n";
        cout << vertices[i].id << ": ";
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


//Add an edge between two existing vertices
bool BiDirGraph::addEdge(int v_start, int v_end, int wt)
{
    bool addedEdge = false;
    bool edge_FAIL = false;

    if ((v_start >= vertexCount) || (v_end > vertexCount))
    {
        edge_FAIL = true;
    }

    if (v_start == v_end)
    {
        edge_FAIL = true;
    }
    else
    {
        matrix[v_end][v_start] = wt;
        matrix[v_start][v_end] = wt;
        edgeCount++;
        addedEdge = true;
    }
    return addedEdge;
}


//reset the weight of a certain edge
bool BiDirGraph::deleteEdge(int v_start, int v_end)
{

    bool deletedEdge = false;
    bool edge_FAIL = false;

    if ((v_end < edgeCount) || (v_end >= edgeCount))
    {
        edge_FAIL = true;
    }
    if (v_start == v_end)
    {
        edge_FAIL = true;
    }
    else
    {
        matrix[v_end][v_start] = 0;
        matrix[v_start][v_end] = 0;
        edgeCount--;
        deletedEdge = true;
    }
    return deletedEdge;
}


//Return the total count of vertices
int BiDirGraph::getCountVertex()
{
    return vertexCount;
}


//Return the total count of Edges
int BiDirGraph::getEdgeCount() 
{
    return edgeCount;
}


//Send in a certain number of vertices to delete
bool BiDirGraph::deleteVertex(int vertx)
{
    bool deletedVertex = false;
    bool vertex_FAIL = false;

    if (vertx > vertexCount)
    {
        vertex_FAIL = true;
    }
    else
    {
        //Delete the columns
        for (int i = 0; i <matrix.size(); i++)
        {
            if (matrix[i].size() > vertx)
            {
                matrix[i].erase(matrix[i].begin() + vertx);
            }
        }
        //Delete the rows
        if (matrix.size() > vertx)
        {
            matrix.erase(matrix.begin() + vertx);
        }

        vertexCount--;
        deletedVertex =true;
    }
    return deletedVertex;
}


//locate a certain vertex based on its ID
bool BiDirGraph::getVertex(int v_id)
{
    bool foundVertex = false;

    for (int i = 0; i < vertices.size(); i++)
    {
        if (v_id == vertices[i].id)
        {
            foundVertex = true;
        }
    }
    return foundVertex;
}


//Depth First Search
void BiDirGraph::DFS()
{
    vector<bool> visited(edgeCount, false);

    for (int i = 0; i < edgeCount; i++)
        if (!visited[i])
            DFS_util(i, visited);
}


//Private utility method that recursively searches all vertices in Matrix
void BiDirGraph::DFS_util(int vertx, vector<bool> &visited)
{
    stack<int> stack;
    if (vertx == vertices[vertx].id)
    {
        stack.push(vertx);

        while (!stack.empty())
        {
            vertx = stack.top();
            stack.pop();

            if (!visited[vertx])
            {
                cout << vertx << " ";
                visited[vertx] = true;
            }

            for (auto i = matrix[vertx].begin(); i != matrix[vertx].end(); ++i)
            {
                if (!visited[*i])
                {
                    stack.push(*i);
                }
            }
        }
    }  
}


