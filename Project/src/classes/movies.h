#ifndef Movies_h
#define Movies_h
#include "video.h"
#include <iostream>
using namespace std;

class Movie : public Video{
    public:
        Movie();
        Movie(string, string, string, float, float, string);
        void show();
        void show_in_line();
};

Movie::Movie() : Video(){ 
}

Movie::Movie(string i, string tit, string g, float tim, float r, string d) : Video(i, tit, g, tim, r, d){
}

void Movie::show() {
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Genre: " << genre << endl;
    cout << "Duration (mins): " << time << endl;
    cout << "Rating (max 5): " << initialRating << endl;
    cout << "Review: " << desc << endl;

    if (get_size(userRatings) > 0) {
        for (int i = 0; i < get_size(userRatings); i++){
            cout << "User ratings: " << userRatings->score << endl;
        }
    } else { cout << "No one has rated this movie yet!" << endl; };
}

void Movie::show_in_line() {
    cout << id << "\t" << title << "\t" << genre << endl;
}

#endif