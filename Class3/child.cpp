#include <iostream>
using namespace std;

class Parent {
    private:
        string parentName;

    public: 
        void myFunction() {
            cout << "Parent class" << endl;
        }
        void setParentName(string name) {
            parentName = name;
        }
        string getParentName() {
            return parentName;
        }
};

class Child: public Parent {
    public:
        void childWrite() {
            cout << "This is a child class" << endl;
        }
};

class GrandChild: public Child {
    public:
        void grandChildWrite() {
            cout << "This is a grandchild class" << endl;
        }
};

int main() {
    Parent parent;
    Child child;
    GrandChild grandchild;

    parent.myFunction();
    child.childWrite();
    grandchild.grandChildWrite();

    grandchild.setParentName("JOhnny");
    cout << "Grandchild parent is "  << grandchild.getParentName() << endl;

    return 0;
};