#include <iostream>
using namespace std;

// Base class
class mom {
    private:
        string momName;

    protected:
        int momAge;

    public: 
        void setMomName(string name) {
            momName = name;
        }

        string getMomName() {
            return momName;
        }
};

// Derived class
class daughter: public mom {
    public: 
        string daughterName;
        daughter(string name, int ageMom) {
            daughterName = name;
            momAge = ageMom;
        }

        int getMomAge() {
            return momAge;
        }
};

int main() {
    daughter one("Joanna", 59);
    one.setMomName("Karen");
    cout << one.daughterName << "'s mom is " << one.getMomName() << " and she's " << one.getMomAge() << endl;

    return 0;
}