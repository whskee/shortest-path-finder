#pragma once

// struct to represent the vertices
struct Node {
    int dest;
    int weight;
    int dsc, fin;
    char color;
    Node* next;
    Node* parent;
};

// struct to represent the edges of the graph
struct AdjList {
    Node* head;
};

// class to represent a graph
class Graph {
public:
    int V, E;
    AdjList* Adj; // array of linked lists
    
    Graph(int V, int E);
    void addEdge(int src, int dest);
    void addEdge(int src, int dest, int weight);
    void performDijkstra(int weight, int src);
    void initSingleSrce();
    void relax();
    void printGraph();
};
