#ifndef Video_h
#define Video_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Video{
    protected:
        string id;
        string title; 
        string genre;
        float time; // Video duration
        float initialRating;
        string desc; // Video description 
        vector<float> userRatings; 

    public:
        Video();
        Video(string, string, string, float, float, string);
        
        void setId(string i){id = i;};
        void setTitle(string tit){title = tit;};
        void setGenre(string g){genre = g;};
        void setTime(float tim){time = tim;};
        void setInitialRating(float r){initialRating = r;};
        void setDesc(string d){desc = d;};
        void setUserRatings(vector<float> rat){userRatings = rat;};
        
        string getId(){return id;};
        string getTitle(){return title;};
        string getGenre(){return genre;};
        float getTime(){return time;};
        float getInitialRating(){return initialRating;};
        string getDesc(){return desc;};
        vector<float> getUserRatings(){return userRatings;};
        
        virtual void show() = 0;
        virtual void show_in_line() = 0;
    };

// Default constructor
Video::Video(){
    id = "";
    title = "";
    genre = "";
    time = 0.0;
    initialRating = 0.0;
    desc = "";
}

// Overloaded constructor
Video::Video(string i, string tit, string g, float tim, float r, string d){
    id = i;
    time = tim;
    title = tit;
    genre = g;
    initialRating = r;
    desc = d;
}

#endif