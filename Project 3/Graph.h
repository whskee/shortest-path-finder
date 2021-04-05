#pragma once

// struct to represent the vertices
typedef struct Vertex {
    int pi;                 // parent index
    char color;
    int dsc, fin;
    float d;                // distance
    int pos;                // index in heap array
}Vertex;


// struct to represent the edges of the graph
typedef struct Node {
    int v;                  // stores vertex id
    float w;                // weight
    Node *next;             // pointer to next element
}Node;


// class to represent a graph
struct Graph {
    Node **Adj;             // array of linked lists
    Vertex *V;
    int vertices;
};


// functions to be implemented in Graph.cpp
Graph* Initialize(int n, int m);
void addEdge(Graph *graph, int src, int dest);
void addEdge(Graph *graph, int src, int dest, int weight);
void performDijkstra(Graph *graph, int weight, int src);
void initSingleSrce();
void relax();
void printGraph(Graph *graph);
