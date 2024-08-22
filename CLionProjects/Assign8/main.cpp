#include <iostream>
#include <fstream>

#include "PQType.h"

using namespace std;

int main() {
    PQType pq;
    string inputFile, outputFile;

    cout << "Enter input file name: ";
    cin >> inputFile;

    cout << "Enter output file name: ";
    cin >> outputFile;

    ifstream input(inputFile);
    if (!input) {
        cerr << "Error: could not open input file\n";
        return 1;
    }

    ofstream output(outputFile);
    if (!output) {
        cerr << "Error: could not open output file\n";
        return 1;
    }

    string command;
    int key, priority;

    while (input >> command) {
        try {
            if (command == "insert") {
                input >> key >> priority;
                pq.insert(key, priority);
            } else if (command == "extractMax") {
                int maxKey = pq.extractMax();
                output << maxKey << endl;
            } else if (command == "isEmpty") {
                output << (pq.isEmpty() ? "true" : "false") << endl;
            } else {
                throw invalid_argument("Invalid command: " + command);
            }
        } catch (const exception& ex) {
            cerr << "Error: " << ex.what() << endl;
            return 1;
        }
    }

    input.close();
    output.close();

    return 0;
}