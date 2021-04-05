#include "util.h"
#include <iostream>
#include <string>

using namespace std;

// get user input and evaluate it
string nextCommand(string &strInput, int &src, int &dest) {

    string input;

    while (1) {
        // get user command and convert it to upper case
        cin >> input;

        if (input == " " || input == "\t" || input == "\n") {
            continue;
        }

        // IMPORTANT: change this!
        if (input == "write" || input == "stop") {
            input = "write path";
            break;
        }

        if (input == "find") {
            cin >> src;
            cin >> dest;
            break;
        }
    }

    return input;
}
