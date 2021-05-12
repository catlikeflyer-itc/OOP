#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        int id;

    public:
        Student(string n, int num) {
            name = n;
            id = num;
        }
        
        void print() {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
        }
};

int main() {
    Student s("Joanne", 10);
    s.print();

    return 0;
}