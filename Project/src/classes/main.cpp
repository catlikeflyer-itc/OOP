#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <typeinfo>
#include <stdlib.h>
#include <random>
#include <vector>
#include <string>
#include "movies.h"
#include "series.h"
  
using namespace std;

// Returns movie vector from movies.csv 
vector<Movie> read_movies() {
    ifstream myFile;
    string line, word, row[6];
    myFile.open("../files/movies.csv");
    int i = 0;
    vector<Movie> movie_v;

    while(getline(myFile, line)) {
        stringstream ss(line);
        int j = 0;

        while(getline(ss, word, ',')) {
            row[j] = word;
            j++;
        }

        // Creates a Movie object
        Movie m(row[0], row[1], row[2], stof(row[3]), stof(row[4]), row[5]);
        movie_v.push_back(m);

        i++;

    }
    myFile.close();

    return movie_v;
}

// Returns a tuple containing an Episode vector and series names string vector from series_full.csv
tuple <vector<Episode>, vector<string>> read_series() {
    ifstream myFile;
    string line, word, row[9];
    myFile.open("../files/series_full.csv");
    int i = 0;
    vector<Episode> ep_v;
    vector<string> series_v;

    while(getline(myFile, line)) {
        stringstream ss(line);
        int j = 0;

        while(getline(ss, word, '\t')) {
            row[j] = word;
            j++;
        }

        // Creates a Movie object
        Episode e(row[0], row[1], row[2], stof(row[3]), stof(row[4]), row[5], row[6], stoi(row[7]), stoi(row[8]));
        ep_v.push_back(e);

        if (!count(series_v.begin(), series_v.end(), row[6])) {
            series_v.push_back(row[6]);
        }

        i++;

    }
    myFile.close();
    return {ep_v, series_v};
}

// Prints menu for user to choose what type of search they'd do
int menu() {
    string user_input;
    bool ready = false;

    while (!ready) {
        cout << "Welcome to Tecsney+\n---------------------------------------------------\nAn online movie catalogue\n\n" << endl;
        cout << "What would you like to do today?: \n" << endl;
        cout << "1. See full catalogue \n2. See movies catalogue \n3. See series catalogue \n4. Search for specific collection" << endl;

        cin >> user_input;

        if (user_input == "1" || user_input == "3" || user_input == "2" || user_input == "4") {
            cout << "Searching..." << endl;
            return stoi(user_input);
        }

        cout << "Invalid choice, try again!!!" << endl; 
    }

    return 404;
}

int main() {
    vector <Movie> mov_ob = read_movies(); // vector de objetos Movie, es decir, vector que tiene todas las peliculas como objetos individuales. (no se si funciona en practica)
    vector <Episode> all_ep_obj = get<0>(read_series()); // vector de objetos Episode, mismo caso que arriba (no estoy seguro de que funcione en práctica)
    vector <string> series_names = get<1>(read_series());
    int choice = menu();

    switch (choice)
    {
    case 1:
        for(int i = 0; i < mov_ob.size(); i++) {
            mov_ob.at(i).show_in_line();
        }

        for(int i = 0; i < all_ep_obj.size(); i++) {
            all_ep_obj.at(i).show_in_line();
        }

        break;

    case 2:
        for(int i = 0; i < mov_ob.size(); i++) {
            mov_ob.at(i).show_in_line();
        }

        break;
    case 3:
        for(int i = 0; i < all_ep_obj.size(); i++) {
            all_ep_obj.at(i).show_in_line();
        }
        
        break;

    default:
        cout << "Error" << endl;
        break;
    }

    return 0;
}
