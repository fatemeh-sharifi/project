#ifndef MUSIC_HPP_INCLUDE
#define MUSIC_HPP_INCLUDE
#include <iostream>
#include <vector>
#include "string_functions.hpp"
#include "Time.hpp"
using namespace std;

class Music
{
    public:
        Music(int id_, string title_, string path_, string time_, string album_, int year_, vector<string> tags_, string artist_);
        void print_info_short();
        void print_all_info();
        bool is_id_for_this_music(int num);
        bool is_music_searched(string name, string artist_name, string tag);
        void print_as_recommended();
        void add_like(){likes_count++;}
        void print_title(){cout << title;}
        int get_likes_count(){return likes_count;}
        int get_id(){return id;}
        Time get_duration(){return duration;}

    private:
        int likes_count = 0;
        int id;
        vector <string> tags;
        string artist;
        Time duration;
        string title;
        string path;
        string album;
        int year;
};

#endif