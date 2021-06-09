#ifndef Series_h
#define Series_h
#include "video.h"
#include "link_list.h"

// Class Series

class Episode : public Video{
    private:
        string seriesTitle; // Title of the initial series
        int season; 
        int episode; 

    public:
        Episode();
        Episode(string, string, string, float, float, string, string, int, int);
        
        void setSeriesTitle(string ti){seriesTitle = ti;};
        void setSeason(int s){season = s;};
        void setEpisode(int c){episode = c;};

        string getSeriesTitle(){return seriesTitle;};
        int getSeason(){return season;};
        int getEpisode(){return episode;};

        void show();
        void show_in_line();
};

Episode::Episode() : Video(){
    seriesTitle = "";
    season = -1;
    episode = -1;
}

Episode::Episode(string i, string tit, string g, float tim, float r, string d, string st, int sea, int ep) : Video(i, tit, g, tim,r, d) {
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

    if (get_size(userRatings) > 0) {
        for (int i = 0; i < get_size(userRatings); i++){
            cout << "User ratings: " << userRatings->score << endl;
        }
    } else { cout << "No one has rated this movie yet!" << endl; };
}

void Episode::show_in_line() {
    cout << id << "\t" << seriesTitle << "\t" << episode << "\t" << title << "\t" << genre << endl;
}

#endif