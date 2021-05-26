#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Students {
    private:
        // Used vectors to avoid separation fault caused when partitioning arrays and to adjust for the amount of lines in the csv.
        vector<int> id;
        vector<string> name;
        vector<int> mark1;
        vector<int> mark2;
        vector<int> average;
        int quantity;

    public:
        void read_info(string path) {
            ifstream myFile;
            string line, word, row[4];
            myFile.open(path);
            int i = 0;

            while(getline(myFile, line)) {
                stringstream ss(line);
                int j = 0;

                while(getline(ss, word, ',')) {
                    row[j] = word;
                    j++;
                }

                id.push_back(stoi(row[0]));
                name.push_back(row[1]);
                mark1.push_back(stoi(row[2])); 
                mark2.push_back(stoi(row[3]));
                average.push_back((mark1[i]+mark2[i])/2);

            i++;
            }

            quantity = id.size();
            myFile.close();
        }

        void print_info() {
            cout << "ID | Name | First mark | Second mark | Average "<< endl << "-----------------------------------------------------------" << endl;

            for(int i = 0; i < id.size(); i++) {
                cout << id.at(i) << "  " << name.at(i) << "  " << mark1.at(i) << "\t\t" << mark2.at(i) << "\t\t" << average.at(i) << endl;
            }
            
            cout << "A total of " << quantity << " students" << endl;

        }

        int search() {
            int index = 0;
            string searchType;
            string searchValue;

            cout << "What do you want to search for? \n 1. Name \n 2. ID \nEnter the corresponding number: " << endl;
            cin >> searchType;
            cout << "Enter info to search for: " << endl;
  

            switch (stoi(searchType)) {
                case 1:
                    cin >> searchValue;
                    cout << "Searching for name" << endl;
                    for (int i = 0; i < id.size(); i++) {
                        if (name[i] == searchValue) {
                            index = i;
                            break;
                        }
                    }
                    break;

                case 2:
                    cin >> searchValue;
                    cout << "Searching for ID" << endl;
                    for (int i = 0; i < id.size(); i++) {
                        if (id[i] == stoi(searchValue)) {
                            index = i;
                            break;
                        }
                    }
                    break;
                
                default:
                    cout << "Invalid choice!!!" << endl;
                    return 1;
                    break;
            }

            if (index == 0) {
                cout << "No data available!!!" << endl;
                return 1;
            }

            cout <<"ID | Name | First mark | Second mark | Average"<< endl << "-----------------------------------------------------------" << endl;
            cout << id[index] << "  " << name[index] << "  " << mark1[index] << "\t\t" << mark2[index] << "\t\t" << average[index] << endl;

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