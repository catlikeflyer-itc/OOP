#include <iostream>
using namespace std;

// Base class
class vehicle {
    public: 
        string brand;

        void honk() {
            cout << "BEEP BEEP" << endl;
        }
};

// Derived class
class car: public vehicle {
    private:
        string model;
    
    public: 
        car(string m, string b) {
            model = m;
            brand = b;
        }
};

int main() {
    car Mustang("Mustang", "Ford");
    cout << Mustang.brand << endl;
    Mustang.honk();

    return 0;
}