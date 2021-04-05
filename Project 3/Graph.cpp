#include "Graph.h"
#include <iostream>

using namespace std;


// function to initialize the graph
Graph::Graph(int n, int m) {
    vertices = n;
    Adj = (Node**) calloc(n+1, sizeof(Node*));           // Adj[u] contains all vertices adjacent to u
    V = (Vertex*) calloc(n+1, sizeof(Vertex*));
}

// function to add unweighted edge
void Graph::addEdge(int src, int dest) {
    Node *node = new Node;
    node->v = dest;
    node->next = Adj[src];
    Adj[src] = node;
}

// function to add weighted edge
void Graph::addEdge(int src, int dest, int weight) {
    Node *node = new Node;
    node->v = dest;
    node->w = weight;
    node->next = Adj[src];
    Adj[src] = node;
}

//void Graph::relax(int u, int v, int w) {
//    if (V[v].d > V[u].d + w) {
//        V[v].d = V[u].d + w;
//        V[v].pi = u;
//        index = V[v].index;
//        decreaseKey(heap, index, V[v].d);
//    }
//}

//int Graph::performDijkstra(int weight, int src) {
//    Q = initialize(vertices);
//    for (int x = 1; x <= vertices; x++) {
//        V[x].d = 0;
//        V[x].color = 'W';
//        V[x].pi = NULL;
//    }
//    V[src].d = 0;
//    V[src].color = 'G';
//    insert(Q, src);
//    Vertex *u;
//    while (Q != NULL) {
//        u = extractMin(Q);
//    }
//    return 1;
//}

void Graph::initSingleSrce(int src) {
    
}

// function to print adjacency list of G
void Graph::printGraph() {
    for (int x = 1; x <= vertices; x++) {
        Node *temp = Adj[x];
        cout << x << ": ";
        while (temp != NULL) {
            cout << " --> " << temp->v;
            temp = temp->next;
        }
        cout << "\n";
    }
}
