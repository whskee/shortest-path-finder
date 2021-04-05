#include "Graph.h"
#include <iostream>

using namespace std;

// function to initialize the graph
Graph* Initialize(int n, int m) {
    Graph* graph = new Graph;
    graph->vertices = n;
    //graph->Adj = new Node[n + 1];            // Adj[u] contains all vertices adjacent to u
    graph->Adj = (Node**) calloc(n+1, sizeof(Node*));
    graph->V = new Vertex[n + 1];
    return graph;
}

// function to add an edge
void addEdge(Graph *graph, int src, int dest) {
    Node *node = new Node;
    node->v = dest;
    node->next = graph->Adj[src];
    graph->Adj[src] = node;
}

// function to add an edge
void addEdge(Graph *graph, int src, int dest, int weight) {
    Node *node = new Node;
    node->v = dest;
    node->w = weight;
    node->next = graph->Adj[src];
    graph->Adj[src] = node;
    
//    cout << "added<" << src << ", " << dest << ", " << weight << ">\n";
//    cout << graph->Adj[src]->w << "\n";
}

void printGraph(Graph *graph) {
    for (int x = 1; x <= graph->vertices; x++) {
        Node *temp = graph->Adj[x];
        cout << x << ": ";
        while (temp != NULL) {
            cout << " --> " << temp->v;
            temp = temp->next;
        }
        cout << "\n";
    }
}
