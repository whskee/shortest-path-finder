#include "Graph.h"
#include <iostream>

using namespace std;

// function to initialize the graph
Graph* Initialize(int V, int E) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->Adj = new AdjList[V + 1]; // Adj[u] contains all vertices adjacent to u
    return graph;
}

// function to add an edge
void addEdge(Graph *graph, int src, int dest) {
    AdjListNode *node = new AdjListNode;
    node->dest = dest;
    node->next = NULL;
    node->next = graph->Adj[src].head;
}

// function to add an edge
void addEdge(Graph *graph, int src, int dest, int weight) {
    AdjListNode *node = new AdjListNode;
    node->dest = dest;
    node->weight = weight;
    node->next = graph->Adj[src].head;
    graph->Adj[src].head = node;
    cout << "added<" << src << ", " << dest << ", " << weight << ">\n";
    cout << graph->Adj[src].head->dest << "\n";
}

void printGraph(Graph *graph) {
    for (int x = 1; x <= graph->V; x++) {
        AdjListNode *temp = graph->Adj[x].head;
        cout << x << ": ";
        while (temp->next != NULL) {
            cout << temp->dest << "-->";
            temp = temp->next;
        }
        cout << "\n";
    }
}
