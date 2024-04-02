#ifndef PLAYLIST_HPP_INCLUDE
#define PLAYLIST_HPP_INCLUDE
#include "Music.hpp"
#include "Errors.hpp"
const string INIT_TIME = "00:00:00";

class Playlist
{
    public:
        Playlist(string name_);
        void print_name(){cout << name;}
        void print_info();
        void print_musics();
        void add_music(Music *music);
        void delete_music(int id);
        bool is_name_equal_to_title(string str);
        string get_name(){return name;}

    private:
        vector <Music*> musics;
        string name;
        Time duration;
};

#endif