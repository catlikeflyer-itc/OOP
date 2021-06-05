#ifndef Video_h
#define Video_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Video{
    protected:
        int id;
        string title; 
        string genre;
        float time; // Video duration
        float initialRating;
        string desc; // Video description 
        vector<float> userRatings; 

    public:
        Video();
        Video(int, string, string, float, float, string);
        
        void setId(int i){id = i;};
        void setTitle(string ti){title = ti;};
        void setGenre(string g){genre = g;};
        void setTime(float t){time = t;};
        void setInitialRating(float r){initialRating = r;};
        void setDesc(string d){desc = d;};
        void setUserRatings(vector<float> rat){userRatings = rat;};
        
        int getId(){return id;};
        string getTitle(){return title;};
        string getGenre(){return genre;};
        float getTime(){return time;};
        float getInitialRating(){return initialRating;};
        string getDesc(){return desc;};
        vector<float> getUserRatings(){return userRatings;};
        
        virtual void show(){cout<<" "<<endl;};
    };

// Default constructor
Video::Video(){
    id = 0;
    title = "";
    genre = "";
    time = 0.0;
    initialRating = 0.0;
    desc = "";
}

// Overloaded constructor
Video::Video(int i, string ti, string g, float t, float r, string d){
    id = i;
    time = t;
    title = ti;
    genre = g;
    initialRating = r;
    desc = d;
}

#endif