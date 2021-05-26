#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string line;
    string row[3];
    string word;
    int i = 0;
    stringstream ss(line);

    while(getline(ss, word, ',')) {
        row[i] = word;
        i++;
    }

    cout << row[0] << endl;

    return 0;
}