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
        float rating; 
        string desc; // Video description 

    public:
        Video();
        Video(int, string, string, float, float, string);
        
        void setId(int i){id = i;};
        void setTitle(string ti){title = ti;};
        void setGenre(string g){genre = g;};
        void setTime(float t){time = t;};
        void setRating(float r){rating = r;};
        void setDesc(string d){desc = d;};
        
        int getId(){return id;};
        string getTitle(){return title;};
        string getGenre(){return genre;};
        float getTime(){return time;};
        float getRating(){return rating;};
        string getDesc(){return desc;};
        
        virtual void show(){cout<<" "<<endl;};
    };

// Default constructor
Video::Video(){
    id = 0;
    title = "";
    genre = "";
    time = 0.0;
    rating = 0.0;
    desc = "";
}

// Overloaded constructor
Video::Video(int i, string ti, string g, float t, float r, string d){
    id = i;
    time = t;
    title = ti;
    genre = g;
    rating = r;
    desc = d;
}

#endif