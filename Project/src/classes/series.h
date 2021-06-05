#ifndef Series_h
#define Series_h
#include "video.h"

// Class Series

class Episode : public Video{
    private:
        string seriesTitle; // Title of the initial series
        int season; 
        int episode; 

    public:
        Episode();
        Episode(int, string, string, float, float, string, string, int, int);
        
        void setSeriesTitle(string ti){seriesTitle = ti;};
        void setSeason(int s){season = s;};
        void setEpisode(int c){episode = c;};

        string getSeriesTitle(){return seriesTitle;};
        int getSeason(){return season;};
        int getEpisode(){return episode;};

        void show();
    };

Episode::Episode(){
    seriesTitle = "";
    season = -1;
    episode = -1;
}

Episode::Episode(int i, string t, string g, float ti, float r, string d, string st, int sea, int ep): Video(i, t, g, ti,r, d) {
    seriesTitle = st;
    season = sea;
    episode = ep;
}

void Episode::show() {
    cout << "ID: " << id << endl;
    cout << "Series Title: " << seriesTitle << endl;
    cout << "Episode Title: " << title << endl;
    cout << "Episode: " << episode << endl;
    cout << "Season: " << season << endl;
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