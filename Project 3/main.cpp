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
    int n, m; // V and E represent the number of vertices and edges respectively
    int src, dest, weight;

    cin >> strInput;
    cin >> graphType;

    // read graph from file
    file.open(strInput);
    if (file.is_open()) {
        file >> n; // get number of vertices
        file >> m; // get number of edges
        graph = new Graph(n, m);

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
        exit(0);
    }

    graph->printGraph();

    while (1) {
        // get user input and pass by reference
        command = nextCommand(strInput, src, dest);

        if (command == "write path") {

            break;
        }

        if (command == "find") {
            break;
        }

        if (command == "stop") {
            exit(0);
        }

        if (command == "print graph") {
            graph->printGraph();
        }
    }
}