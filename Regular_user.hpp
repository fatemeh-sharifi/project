#ifndef REGULAR_USER_HPP_INCLUDE
#define REGULAR_USER_HPP_INCLUDE
#include "User.hpp"

class Regular_user : public User
{
    public:
        Regular_user(string name_, string password_, int id_, string mode_);
        void print_info_short();
        void print_all_info();
        bool is_user_artist(){return false;}
        bool is_user_regular(){return true;}
        void delete_music(int id_);
        void add_music_to_playlist(Music *music, string playlist_name);
        void print_playlists();
        void delete_playlist(string name);
        bool add_playlist(string playlist_name);
        void like_music(Music *music);
        void print_liked_musics();
        void print_specific_playlist(string playlist_name);
        bool is_music_liked(Music *music);

        bool is_music_for_artist(Music *music){throw Permission_denied_ex();}
        void add_music(Music *music){throw Permission_denied_ex();}
        void print_registered_music(){throw Permission_denied_ex();}
        
    private:
        vector<Music*> liked_musics;
        vector<Playlist> playlists;

};

#endif