#include <iostream>
using namespace std;

class Hotel {
    public: 
        int roomNo;
        string password;
        int price;

        Hotel(int roomNum, string roomPass, int roomPrice) {
            roomNo = roomNum;
            password = roomPass;
            price = roomPrice;
        }
};

class Client: private Hotel {
    protected: 
        int clientID;
        string clientName;

    public: 
        Client(int roomNum, string roomPass, int roomPrice, int ID, string name): Hotel(roomNum, roomPass, roomPrice) {
            clientID = ID;
            clientName = name;
        }

        float totalPrice(int nights){
            return price*nights;
        }

        void printInfo() {
            cout << "Name: " << clientName << endl;
            cout << "ID: " << clientID << endl;
            cout << "Room Number: " << roomNo << endl;
            cout << "Password: " << password << endl;
            cout << "Price per night: " << price << endl;
        }      
};

int main() {
    Client client1(12, "Hello1234", 123, 1, "Johnny Bravo");

    client1.printInfo();
    cout << "Total price for 10 nights is " << client1.totalPrice(10) << endl; 
};