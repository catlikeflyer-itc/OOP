#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int *pointer = &x;
    cout << "The location of x is " << pointer << endl;
    cout << "The value of x is " << *pointer << endl;

    return 0;
}