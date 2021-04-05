#include "Graph.h"
#include "heap.h"
#include "util.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    // input variables
    int input;
    string command, strInput, graphType;
    ifstream file;

    // graph variables
    Graph *graph;
    int V, E; // V and E represent the number of vertices and edges respectively
    int src, dest, weight;

    //cin >> strInput;
    //cin >> graphType;

    graphType = "directed";

    // read graph from file
    file.open("network01.txt");
    if (file.is_open()) {
        file >> V; // get number of vertices
        file >> E; // get number of edges
        graph = new Graph(V, E);

        // get input from file
        while (file >> input) {
            file >> src;
            file >> dest;
            file >> weight;
            graph->addEdge(src, dest, weight);
            if (graphType == "undirected") {
                graph->addEdge(dest, src, weight);
            }
        }
        file.close();
    } else {
        cout << "Error: cannot open file for reading\n";
    }

    while (1) {
        // get user input and pass by reference
        command = nextCommand(strInput, src, dest);

        if (command == "write path") {
            cout << "Done";
            break;
        }

        if (command == "find") {
            break;
        }

        if (command == "stop") {
            exit(0);
        }
    }
}