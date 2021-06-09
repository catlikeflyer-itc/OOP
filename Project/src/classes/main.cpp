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
#include "link_list.h"
  
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
tuple <vector<Episode>, vector<string>, vector<string>> read_series() {
    ifstream myFile;
    string line, word, row[9];
    myFile.open("../files/series_full.csv");
    int i = 0;
    vector<Episode> ep_v;
    vector<string> series_v;
    vector<string> genre_list;

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

        if (!count(series_v.begin(), series_v.end(), row[2])) {
            series_v.push_back(row[2]);
        }

        i++;

    }
    myFile.close();
    return {ep_v, series_v, genre_list};
}

// Prints menu for user to choose what type of search they'd do, returns the int of the option the user chose
int menu() {
    string user_input;
    bool ready = false;

    while (!ready) {
        cout << "Welcome to Tecsney+\n---------------------------------------------------\nAn online movie catalogue\n\n" << endl;
        cout << "What would you like to do today?: \n" << endl;
        cout << "1. See full catalogue \n2. See movies catalogue \n3. See series catalogue \n4. Search for specific collection \n5. Search by rating range \n6. Search by genre" << endl;

        cin >> user_input;

        if (user_input == "1" || user_input == "3" || user_input == "2" || user_input == "4" || user_input == "5" || user_input == "6") {
            cout << "Searching..." << endl;
            return stoi(user_input);
        }

        cout << "Invalid choice, try again!!!" << endl; 
    }

    return 404;
}

// Takes user choice as parameter to print the data of the information requested by the user
void query_search(int choice, vector <Movie> mov_ob, vector <Episode> ep_obj, vector <string> series_list, vector <string> genre_list) {
    string input;
    string min_rat;
    string max_rat;

    switch (choice) {
        case 1: // Query all
            for(int i = 0; i < mov_ob.size(); i++) {
                mov_ob.at(i).show_in_line();
            }

            for(int i = 0; i < ep_obj.size(); i++) {
                ep_obj.at(i).show_in_line();
            }

            break;

        case 2: // Query movies
            for(int i = 0; i < mov_ob.size(); i++) {
                mov_ob.at(i).show_in_line();
            }

            break;

        case 3: // Query series episodes
            for(int i = 0; i < ep_obj.size(); i++) {
                ep_obj.at(i).show_in_line();
            }
            
            break;

        case 4: // Query by exact title
            cout << "Enter the exact title: (series or movie)" << endl; //**NEEDS FIX
            getline(cin, input);
            
            for (int i = 0; i < mov_ob.size(); i++) {
                if (input == mov_ob.at(i).getTitle()) {
                    mov_ob.at(i).show_in_line();
                }
            }

            for (int i = 0; i < series_list.size(); i++) {
                if (input == series_list.at(i)) {
                    for (int j = 0; j < ep_obj.size(); j++) {
                        if (series_list.at(i) == ep_obj.at(j).getSeriesTitle()) {
                            ep_obj.at(j).show_in_line();
                        }
                    }
                }
            }
            
            break;

        case 5: // Query by range of ratings
            cout << "Minimun rating (max 5): " << endl;
            cin >> min_rat;
            cout << "Max rating (max 5): " << endl;
            cin >> max_rat;

            for (int i = 0; i < mov_ob.size(); i++) {
                if (mov_ob.at(i).getInitialRating() >= stof(min_rat) && mov_ob.at(i).getInitialRating() <= stof(max_rat)) {
                    mov_ob.at(i).show_in_line();
                }
            }

            for (int j = 0; j < ep_obj.size(); j++) {
                if (ep_obj.at(j).getInitialRating() >= stof(min_rat) && ep_obj.at(j).getInitialRating() <= stof(max_rat)) {
                    ep_obj.at(j).show_in_line();
                }
            }
        
            break;

        default:
            cout << "Error" << endl;

            break;
    }
};

string ask4ID() {
    string id;
    cout << "Write the ID of the video:" << endl;
    cin >> id;

    return id;
}

// Asks the user if they'd like to see more details about a certain video or if they'd like to rate one
int more_deets(vector <Movie> mov_ob, vector <Episode> ep_ob) {
    string c;
    string id;

    bool get = false;
    int index = 0;
    float score;
    struct Node* head = NULL;

    cout << "1. Rate a video \n2. Get more details \n3. Exit program" << endl;
    cin >> c;

    switch (stoi(c)) {
        case 1: // Rate
            id = ask4ID();

            
            
            for (int i = 0; i < mov_ob.size(); i++) {
                if (mov_ob.at(i).getId() == id) {
                    add_score(&head, mov_ob.at(i).getInitialRating());
                    index = i;
                    get = true;
                    break;
                }
            }

            if(get != true){
                for (int j = 0; j < ep_ob.size(); j++) {
                    if (ep_ob.at(j).getId() == id) {
                        add_score(&head, ep_ob.at(j).getInitialRating());
                    }
                }
            }

            cout << "\n\nIngrese el rating que desea otorgarle al video" << endl;
            cin >> score;
            add_score(&head,score);

            cout << "El rating actual del video es: " << show_avg(head) << "\nMuchas gracias por su contribucion!" << endl;

            return 0;
            break;

        case 2: // More details
            id = ask4ID();
            
            for (int i = 0; i < mov_ob.size(); i++) {
                if (mov_ob.at(i).getId() == id) {
                    mov_ob.at(i).show();
                }
            }

            for (int j = 0; j < ep_ob.size(); j++) {
                if (ep_ob.at(j).getId() == id) {
                    ep_ob.at(j).show();
                }
            }
            
            return 0;
            break;
        
        default:
            cout << "Thanks for using the program!" << endl;
            break;
            return 1;
    }

    return 0;
}

int main() {
    vector <Movie> mov_ob = read_movies(); // vector de objetos Movie, es decir, vector que tiene todas las peliculas como objetos individuales. (no se si funciona en practica)
    vector <Episode> all_ep_obj = get<0>(read_series()); // vector de objetos Episode, mismo caso que arriba (no estoy seguro de que funcione en práctica)
    vector <string> series_names = get<1>(read_series());
    vector <string> genre_list = get<2>(read_series());
    int choice = menu();

    query_search(choice, mov_ob, all_ep_obj, series_names, genre_list); // SHows basic info of the videos fitting on the requested query


    int details_choice = more_deets(mov_ob, all_ep_obj); // Gets an int to evaluate whether to run or stop the program

    return 0;
}
