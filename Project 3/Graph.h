#pragma once

// struct to represent the vertices
struct AdjListNode {
    int dest;
    int weight;
    int dsc, fin;
    char color;
    AdjListNode *next;
    AdjListNode *parent;
};

// struct to represent the edges of the graph
struct AdjList {
    AdjListNode *head;
};

// class to represent a graph
struct Graph {
    int V, E;
    AdjList *Adj; // array of linked lists
};

Graph* Initialize(int V, int E);
void addEdge(Graph *graph, int src, int dest);
void addEdge(Graph *graph, int src, int dest, int weight);
void performDijkstra(Graph *graph, int weight, int src);
void initSingleSrce();
void relax();
void printGraph(Graph *graph);
