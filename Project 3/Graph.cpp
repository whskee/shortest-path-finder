#include "Graph.h"
#include <iostream>

using namespace std;

// parameterized constructor
Graph::Graph(int n, int m) {
    vertices = n;
    Adj = (Node **)calloc(n + 1, sizeof(Node *)); // Adj[u] contains all vertices adjacent to u
    V = (Vertex *)calloc(n + 1, sizeof(Vertex *));
}

// destructor
Graph::~Graph() {
    delete Adj;
    delete V;
}

// function to add unweighted edge
void Graph::addEdge(int s, int dest) {
    Node *node = new Node;
    node->v = dest;
    node->next = Adj[s];
    Adj[s] = node;
}

// function to add weighted edge
void Graph::addEdge(int s, int dest, float w) {
    Node *node = new Node;
    node->v = dest;
    node->w = w;
    node->next = Adj[s];
    Adj[s] = node;
}

void Graph::relax(int u, int v, int w) {
    if (V[v].d > V[u].d + w) {
        V[v].d = V[u].d + w;
        V[v].pi = u;
    }
}

int Graph::performDijkstra(int w, int s) {
    initSingleSrce(s);
    Q = new MinHeap(vertices);
    Q->insert(s, V[s].d);

    int u;
    while (Q != NULL) {
        u = Q->extractMin();
        V[u].color = 'B';

        if (u == t) {
            return 0;
        }

        Node *temp = Adj[u];

        while (temp != NULL) {
            v = temp->v;
            if (V[v].color == 'W') {
                V[v].d = V[u].d + temp->w;
                V[v].pi = u;
                V[v].color = 'G';
                Q->insert(v, V[v].d);
            } else if (V[v].d > V[u].d + temp->w) {
                relax(u, v, temp->w);
            }
            temp = temp->next;
        }
        Q->printHeap();
    }
    return 1;
}

void Graph::initSingleSrce(int s) {
    for (int x = 1; x <= vertices; x++) {
        V[x].d = 0;
        V[x].color = 'W';
        V[x].pi = NULL;
    }
    V[s].d = 0;
    V[s].color = 'G';
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
