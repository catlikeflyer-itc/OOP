#include <iostream>
using namespace std;

int sum(int a, int b){ // function must include 3 things, type of return (void if nothing), name and arguments. Arguments are made by defining type, and name. There is no limit
    return a+b; // if it does not return something, it will mark error!
}

void printStuff(int value){ // this is also called the signature/headding/prototype of the function
    cout << "value is: " << value << endl;
    return; // void returns nothing, so it is not necesary, but cool stuff can be done
}

int main(){
    // declaration of variables

    int * poinerToInt;
    double * poinerToDouble;
    float * poinerToFloat;
    bool * poinerToBool;
    int * z;

    // non pointer vars

    int a = 10;
    int b = 15;
    int c = 20;

    // make pointer point to a
    poinerToInt = &a;

    // now print

    cout << "pointer is pointing to: " << poinerToInt << endl;
    cout << "pointer of a is: " << &a << endl;
    cout << "the value of a but in pointer is: " << *poinerToInt << endl;
    cout << "the pultiplication of pointer to pointer is: " << *poinerToInt * *poinerToInt << endl;// to multiply, use * * with a space, or esle it means something else, the first * is multiply, second one is *var dereference var

    // reserve HEAP memory space

    z = new int;

    // now fill it in

    *z = 100;

    cout << "pointer z is pointing to: " << z << endl;
    cout << "pointer z is has: " << *z << endl;

    delete z; // deletes the reference, and the contents of it!
    //delete poinerToInt; 

    printStuff(sum(10, 20));
}