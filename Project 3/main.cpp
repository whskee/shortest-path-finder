#include "Graph.h"
#include "heap.h"
#include "util.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    // std::cout << argv[0] << std::endl;

    // if (argc < 2) {
    //     // Tell the user how to run the program
    //     std::cerr << "Usage: " << argv[0] << " NAME" << std::endl;
    // }

    // input variables
    int input;
    string command, strInput, graphType;
    ifstream file;

    // graph variables
    Graph *graph;
    int n, m; // V and E represent the number of vertices and edges respectively
    int src, dest;
    float weight;
    int flag;

    cin >> strInput;
    cin >> graphType;

    // read graph from file
    file.open(strInput);

    if (argc > 0) {
        strInput = argv[1];
        graphType = argv[2];
        file.open(strInput);
    } else {
        cin >> strInput;
        cin >> graphType;
    }

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
        command = nextCommand(strInput, src, dest, flag);

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