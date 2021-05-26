#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class student {
  private:
    int id[15];
    string name[15];
    int mark1[15];
    int mark2[15];
    int quantity;

  public:
    void read_info(){
        ifstream file;
        file.open("t1.csv");
        string line,word;
        string row[4];
        quantity = 0;
        int j = 0;

        while(getline(file,line)){
            quantity ++;
            stringstream ss(line);
            int i = 0;

                while(getline(ss,word,',')){
                    row[i] =word;
                    i++;
                }

            id[j] = stoi(row[0]);
            name[j] = row[1];
            mark1[j] = stoi(row[2]); 
            mark2[j] = stoi(row[3]);

            j++;
        }

        file.close();
    }

    void show_info(){
        cout <<"ID| Name | First mark | Second mark  "<<endl<< "-----------------------------------------------------------"<<endl;

        for(int i = 0; i<quantity;i++) {
            cout<< id[i]<<"\t"<< name[i]<<"\t\t"<< mark1[i]<<"\t\t\t"<<mark2[i]<<endl;
        }
    }
};

int main() {
    student s;
    
    s.read_info();
    s.show_info();

     return 0;
}
