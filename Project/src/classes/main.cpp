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

// Returns Episode vector from series_full.csv
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


int main(){
    vector <Movie> mov_ob = read_movies(); // vector de objetos Movie, es decir, vector que tiene todas las peliculas como objetos individuales. (no se si funciona en practica)
    vector <Episode> all_ep_obj = get<0>(read_series()); // vector de objetos Episode, mismo caso que arriba (no estoy seguro de que funcione en práctica)
    vector <string> series_names = get<1>(read_series());

    cout << "funciona" << endl;

    cout << "Movies catalogue:" << endl;

    for(int i = 0; i < mov_ob.size(); i++) {
        cout << mov_ob.at(i).getTitle() << endl;
    }

    cout << "Series catalogue:" << endl;
    
    for(int i = 0; i < series_names.size(); i++) {
        cout << series_names.at(i) << endl;
    }

    return 0;
}
