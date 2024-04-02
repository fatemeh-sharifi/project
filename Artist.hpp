#ifndef ARTIST_HPP_INCLUDE
#define ARTIST_HPP_INCLUDE
#include "User.hpp"

class Artist : public User
{
    public:
        Artist(string name_, string password_, int id_, string mode_);
        void print_info_short();
        void print_all_info();
        bool is_user_artist(){return true;}
        bool is_user_regular(){return false;}
        void add_music(Music *music);
        void print_registered_music();
        void delete_music(int id_);
        bool is_music_for_artist(Music *music);

        void delete_playlist(string name){throw Permission_denied_ex();}
        bool add_playlist(string playlist_name){throw Permission_denied_ex();}
        void print_playlists(){throw Bad_req_ex();}
        void add_music_to_playlist(Music *music, string playlist_name){throw Permission_denied_ex();}
        void like_music(Music *music){throw Permission_denied_ex();}
        void print_liked_musics(){throw Permission_denied_ex();}
        void print_specific_playlist(string playlist_name){throw Bad_req_ex();}
        bool is_music_liked(Music *music){throw Permission_denied_ex();}
        
    private:
        vector<Music*> musics;
};

#endif