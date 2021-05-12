#include <iostream>
using namespace std;

class Employee {
    private:
        int salary;

    public:
        void setSalary(int s) {
            salary = s;
        }
        int getSalary() {
            return salary;
        }
};

int main() {
    Employee Juan;
    Juan.setSalary(100000);
    cout << "Juan's Salary is " << Juan.getSalary() << endl;

    return 0;
}