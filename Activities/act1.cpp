#include <iostream>
using namespace std;

class student {
    private:
        string name;
        int id;
        int mark1;
        int mark2;

    public:
        student(string n, int num, int m1, int m2) {
            name = n;
            id = num;
            mark1 = m1;
            mark2 = m2;
        }
        
        float average() {
            return (mark1+mark2)/2;
        }

        void print() {
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Mark 1: " << mark1 << endl;
            cout << "Mark 2: " << mark2 << endl;
        }
};

int main() {
    student s1("Joanne", 10, 98, 89);
    student s2("Juan", 23, 100, 73);
    
    cout << "The student below has a better average." << endl;
    if (s1.average() > s2.average()) {
        s1.print();
    }
    else if (s2.average() > s1.average()) {
        s2.print();
    } 
    else {
        cout << "Same averages" << endl;
        s1.print();
        s2.print();
    }
    
    return 0;
}