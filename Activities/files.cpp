#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Students {
    private:
        int id[15];
        string name[15];
        int mark1[15];
        int mark2[15];
        int average[15];
        int n;

    public:
        void read_info(string path) {
            ifstream myFile;
            string line, word, row[4];
            myFile.open(path);
            int i = 0;

            while(getline(myFile, line)) {
                stringstream ss(line);
                n++;
                int j = 0;

                while(getline(ss, word, ',')) {
                    row[j] = word;
                    j++;
                }

                id[i] = stoi(row[0]);
                name[i] = row[1];
                mark1[i] = stoi(row[2]); 
                mark2[i] = stoi(row[3]);
                average[i] = (mark1[i]+mark2[i])/2;

            i++;
            }

            myFile.close();
        }

        void print_info() {
            cout <<"ID | Name | First mark | Second mark | Average "<< endl << "-----------------------------------------------------------" << endl;

            for(int i = 0; i < n; i++) {
                cout << id[i] << "\t" << name[i] << "\t\t" << mark1[i] << "\t\t\t" << mark2[i] << "\t\t\t" << average[i] << endl;
            }
        }

        int search() {
            int searchType;
            string searchValue;
            int index;
            cout << "What do you want to search for? \n 1. Name \n 2. ID \n" << endl;
            cin >> searchType;

            switch (searchType) {
                case 1:
                    for (int i = 0; i < n; i++) {
                        if (name[i] == searchValue) {
                            index = i;
                            break;
                        } else {
                            cout << "Data doesn't exist!!!" << endl;
                            return 1;
                        }
                    }
                    break;

                case 2:
                    for (int i = 0; i < n; i++) {
                        if (id[i] == stoi(searchValue)) {
                            index = i;
                            break;
                        } else {
                            cout << "Data doesn't exist!!!" << endl;
                            return 1;
                        }
                    }
                    break;
                
                default:
                    cout << "Invalid choice!!!" << endl;
                    return 1;
                    break;
            }

            cout <<"ID | Name | First mark | Second mark | Average"<< endl << "-----------------------------------------------------------" << endl;
            cout << id[index] << "\t" << name[index] << "\t\t" << mark1[index] << "\t\t\t" << mark2[index] << "\t\t\t" << average[index] << endl;

            return 0;
        }
};

int main() {
    Students group1;

    group1.read_info("t1.csv");
    group1.print_info();
    group1.search();

    return 0;
}