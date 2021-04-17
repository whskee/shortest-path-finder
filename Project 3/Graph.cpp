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

void Graph::relax(int u, int v, float w) {
    if (V[v].d > V[u].d + w) {
        float fVal = V[u].d + w;

        // no min-heap operations are printed if flag is 0
        if (flagFind)
            printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", v, V[v].d, fVal);

        V[v].d = V[u].d + w;
        V[v].pi = u;
    }
}

// function to perform DFS on graph
int Graph::performDijkstra(int flagFind, int s, int t) {
    // initialize the min-heap with only the source vertex s
    initSingleSrce(s);

    //Insert s into initially empty Q
    Q = new MinHeap(vertices);

    Q->insert(s, V[s].d, V[s].index, flagFind);

    int u;

    while ((Q != NULL) && (Q->size > 0)) {
        u = Q->extractMin(flagFind);

        if (u == 0)
            return 0;
        //u is removed from heap, hence set its index to 0
        V[u].index = 0;

        if (Q->size > 0) {
            V[Q->arr[1]->u].index = 1;
        }
        if (u == t) {
            return 1;
        }

        Node *temp = Adj[u];

        while (temp != NULL) {
            int v = temp->v;
            if (V[v].color == 'W') {
                V[v].d = V[u].d + temp->w;
                V[v].pi = u;
                V[v].color = 'G';
                Q->insert(v, V[v].d, V[v].index, flagFind);
            } else if (V[v].d > V[u].d + temp->w) {
                relax(u, v, temp->w);

                Q->decreaseKey(V[v].index, V[v].d, flagFind);
            }
            temp = temp->next;
        }
        V[u].color = 'B';
    };
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
