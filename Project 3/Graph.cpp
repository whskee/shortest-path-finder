#include "Graph.h"
#include <iostream>

using namespace std;

// function to initialize the graph
Graph::Graph(int V, int E)
{
    this->V = V;
    this->E = E;
    Adj = new AdjList[V + 1]; // Adj[u] contains all vertices adjacent to u
}

// function to add an edge
void Graph::addEdge(int src, int dest)
{
    Node *node = new Node;
    node->dest = dest;
    node->next = NULL;
    node->next = Adj[src].head;
}

// function to add an edge
void Graph::addEdge(int src, int dest, int weight)
{
    Node *node = new Node;
    node->dest = dest;
    node->weight = weight;
    node->next = Adj[src].head;
}

void Graph::printGraph()
{

    for (int x = 1; x <= V; x++)
    {
        AdjList temp = Adj[x];
        while (temp.head != NULL)
        {
            cout << temp.head[x].dsc;
        }
    }
}
