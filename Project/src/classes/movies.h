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

    if (userRatings.size() > 0) {
        for (int i = 0; i < userRatings.size(); i++){
            cout << "User ratings: " << userRatings[i] << endl;
        }
    } else { cout << "No one has rated this movie yet!" << endl; };
}

#endif