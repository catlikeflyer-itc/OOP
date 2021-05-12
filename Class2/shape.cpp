#include <iostream>
#include <math.h>
using namespace std;

double PI = 3.141592;

class shape {
    private:
        float radius;
        float side;

    public: 
        shape(float r, float s) {
            radius = r;
            side = s;
        }

        float circlePerimeter() {
            return 2*PI*radius;
        }

        float circleArea() {
            return pow(radius, 2)*PI;
        }

        float squarePerimeter() {
            return 4*side;
        }

        float squareArea() {
            return pow(side, 2);
        }
};

int main() {
    shape circle(5, 0);
    shape square(0, 3);
    cout << "Area del cuadrado es " << square.squareArea() << endl;
    cout << "Perimetro del circulo es " << circle.circleArea() << endl;
};