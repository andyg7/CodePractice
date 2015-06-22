
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        // Do something with the line
    }
    return 0;
} 