#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readFile(string path) {
    string myText;
    ifstream myFile;

    myFile.open(path);

    while (getline(myFile, myText)) {
        cout << myText << endl;
    }

    myFile.close();
}

void writeFile() {
    ofstream myFile;
    int lines;
    int ID;
    string name;
    int mark;

    myFile.open("test.csv");

    cout << "Lines to add: " << endl;
    cin >> lines;

    for (int i = 0; i < lines; i++) {
        cout << "ID: " << endl;
        cin >> ID;
        cout << "Name: " << endl;
        cin >> name;
        cout << "Mark: " << endl;
        cin >> mark;

        myFile << ID << "," << name << "," << mark << endl;
    }

    myFile.close()

}

int main() {
    writeFile();
    readFile("test.csv");
   
   return 0;
}