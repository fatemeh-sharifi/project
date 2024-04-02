#ifndef SPOTIFY_HPP_INCLUDE
#define SPOTIFY_HPP_INCLUDE

#include <iostream>
#include <vector>
#include "string_functions.hpp"
#include "Regular_user.hpp"
#include "Artist.hpp"
#include "Music.hpp"
#include "Errors.hpp"
#include "consts.hpp"
using namespace std;

const int FIRST_MUSIC_ID = 1;

class Spotify
{
public:
    ~Spotify();
    void add_user(string username, string password, string mode);
    void login(string username, string password);

    void add_music(string title, string path, string year, string album, string tags, string duration);
    User* find_loged_in_user();

    int users_count(){ return users.size(); }
    User* find_user_by_id(int num);
private:
    vector<User *> users;
    vector<Music *> musics;
    int last_music_id = FIRST_MUSIC_ID;

    User *find_user_by_name(string name);
    
    Music *find_music_by_id(int id);
    int find_music_index(Music *music);

    void logout_user(vector<string>& command);
    void print_users_info(vector<string>& command);
    void print_all_users();
    void print_specific_user(int id);
    
    void print_musics_info(vector<string>& command);
    void print_specific_music(int id);
    void delete_music(vector<string>& command);

    void add_playlist_user(vector<string>& command);
    
    void get_registered_music_artist();
    void add_music_to_playlist(vector<string>& command);
    void search_music(vector<string>& command);
    void print_playlists(vector<string>&  command);

    void follow_user(vector<string>& command);
    void unfollow_user(vector<string>& command);

    void delete_playlist(vector<string>& command);
    void like_music(vector<string>& command);
    void show_recommendations();
    void print_liked_musics();
};

#endif