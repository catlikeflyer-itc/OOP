#include <iostream>
using namespace std;

class Math {
    public:
        int x;
        int y;
    
    int sum(){
        return x+y;
    }

    int multi() {
        return x*y;
    }

    float div() {
        return x/y;
    }
};

int main() {
    Math p, p2;
    p.x = 1;
    p.y = 5;
    p2.x = 10;
    p2.y = 15;
    cout << "La suma de p es: " << p.sum() << endl;
    cout << "Lamultiplicacion de p2 es: " << p2.multi() << endl;

    return 0;
}