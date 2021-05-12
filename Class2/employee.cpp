#include <iostream>
using namespace std;

class Employee {
    protected: 
        int salary;
        int salaryWithBonus;
};

class Programmer: public Employee {
    public: 
        Programmer(int sal) {
            salary = sal;
        }
        void setSalaryWithBonus(int bonus) {
            salaryWithBonus = salary + bonus;
        }
        int getSalary() {
            return salary;
        }
        void print() {
            cout << "Base salary: " << salary << endl;
            cout << "Sabalry with Bonus " << salaryWithBonus << endl;
        }
};

int main() {
    Programmer progra1(10000);
    progra1.setSalaryWithBonus(1000);
    cout << progra1.getSalary() << endl;
    progra1.print();

    return 0;
};