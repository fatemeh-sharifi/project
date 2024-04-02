#ifndef USER_HPP_INCLUDE
#define USER_HPP_INCLUDE

#include <iostream>
#include <vector>
#include "Music.hpp"
#include "Playlist.hpp"
#include "Errors.hpp"
using namespace std;

class User
{
    public:
        User(string name_, string password_, int id_, string mode_);
        bool log_in(string password);
        bool is_name_equal_to_username(string str);
        bool is_num_equal_to_id(int num);
        string get_username(){return name;}
        void remove_from_following(User *user);
        void remove_from_followers(User *user);
        void add_to_followers(User *user);
        void add_to_following(User *user);
        void log_out();
        
        virtual void print_info_short() = 0;
        virtual void print_all_info() = 0;
        virtual void add_music(Music *music) = 0;
        virtual bool add_playlist(string playlist_name) = 0;
        virtual bool is_user_artist() = 0;
        virtual bool is_user_regular() = 0;
        virtual void print_registered_music() = 0;
        virtual void delete_music(int id_) = 0;
        virtual bool is_music_for_artist(Music *music) = 0;
        virtual void add_music_to_playlist(Music *music, string playlist_name) = 0;
        virtual void print_playlists() = 0;
        virtual void delete_playlist(string name) = 0;
        virtual void like_music(Music *music) = 0;
        virtual void print_liked_musics() = 0;
        virtual void print_specific_playlist(string playlist_name) = 0;
        virtual bool is_music_liked(Music *music) = 0;
        bool is_loged_in(){ return loged_in; }
        string get_name(){ return name; }
        string get_mode(){ return mode; }

    private:
        int find_user_index_in_following(User *user);
        int find_user_index_in_followers(User *user);
        vector<User*> followers;
        vector<User*> followings;
        bool loged_in = true;

    protected:
        void print_common_info();
        string name;   
        string password;
        string mode;
        int id;
};

#endif