#pragma once

#include "heap.h"

// struct to represent Vertex attributes
struct Vertex {
    int pi;                 // parent index
    char color;
    int dsc, fin;
    float d;                // distance
    int index;                // index in heap array
};


// Linked List to represent the edges of the graph
struct Node {
    int v;                  // stores vertex id
    float w;                // weight
    Node *next;             // pointer to next element
};


// struct to represent a graph
//struct Graph {
//    Node **Adj;             // array of linked lists, Adj[u] contains all vertices adjacent to u
//    Vertex *V;
//    int vertices;
//};

// functions to be implemented in Graph.cpp
//Graph* Initialize(int n, int m);
//void addEdge(Graph *graph, int src, int dest);
//void addEdge(Graph *graph, int src, int dest, int weight);
//int performDijkstra(Graph *graph, int weight, int src);
//void initSingleSrce(Graph *graph, int src);
//void relax(int u, int v, int w);
//void printGraph(Graph *graph);

class Graph {
public:
    Node **Adj;             // array of linked lists, Adj[u] contains all vertices adjacent to u
    Vertex *V;
    int index;
    MinHeap *Q;
    int vertices;
    
    // functions to be implemented in Graph.cpp
    Graph(int n, int m);
    void addEdge(int src, int dest);
    void addEdge(int src, int dest, int weight);
    int performDijkstra(int weight, int src);
    void initSingleSrce(int src);
    void relax(int u, int v, int w);
    void printGraph();
};


