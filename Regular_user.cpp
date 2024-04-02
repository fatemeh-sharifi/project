#include "Regular_user.hpp"
#include "consts.hpp"
#include <algorithm>

void Regular_user::delete_music(int id_)
{
    for(int i=0; i < playlists.size(); i++)
    {
        playlists[i].delete_music(id_);
    }

    for(int i=0; i < liked_musics.size(); i++)
    {
        if(liked_musics[i]->is_id_for_this_music(id_))
            liked_musics.erase(liked_musics.begin() + i);
    }
}

bool Regular_user::add_playlist(string playlist_name)
{
    for(int i = 0; i < playlists.size(); i++)
    {
        if(playlists[i].is_name_equal_to_title(playlist_name))
        {
            return false;
        }
    }

    playlists.push_back(Playlist(playlist_name));
    return true;
}

void Regular_user::add_music_to_playlist(Music *music, string playlist_name)
{
    for(int i=0; i < playlists.size(); i++)
    {
        if(playlists[i].is_name_equal_to_title(playlist_name))
        {
            playlists[i].add_music(music);
            return;
        }
    }

    throw Not_found_ex();
}

void Regular_user::print_playlists()
{
    if(playlists.size() == 0)
        throw Empty_ex();
    
    sort(playlists.begin(), playlists.end(), [](Playlist& a, Playlist& b){return a.get_name() < b.get_name();});
    cout << PLAYLIST_INFO_COLUMNS << endl;
    for(int i = 0; i < playlists.size(); i++)
    {
        playlists[i].print_info();
    }
}

void Regular_user::print_info_short()
{
    cout << id << DIVIDER;
    cout << mode << DIVIDER;
    cout << name << DIVIDER;
    cout << playlists.size() << endl;
}

void Regular_user::print_all_info()
{
    print_common_info();
    cout << PLAYLISTS;
    for(int i=0; i < playlists.size(); i++)
    {
        if(i == playlists.size() - 1)
        {
            playlists[i].print_name();
            cout << endl;
            break;
        }

        playlists[i].print_name();
        cout << DIVIDER;
    }

    if(playlists.size() == 0)
    {
        cout << endl;
    }
}

void Regular_user::delete_playlist(string name)
{
    for(int i=0; i < playlists.size(); i++)
    {
        if(playlists[i].is_name_equal_to_title(name))
        {
            playlists.erase(playlists.begin() + i);
            return;
        }
    }

    throw Not_found_ex();
}

void Regular_user::like_music(Music *music)
{
    for(int i=0; i < liked_musics.size(); i++)
    {
        if(liked_musics[i] == music)
        {
            throw Bad_req_ex();
        }
    }

    liked_musics.push_back(music);
    music->add_like();
}

void Regular_user::print_liked_musics()
{
    if(liked_musics.size() == 0)
    {
        throw Empty_ex();
    }

    cout << FAVORITE_MUSIC_COLUMNS << endl;
    for(int i=0; i < liked_musics.size(); i++)
    {
        liked_musics[i]->print_info_short();
        cout << endl;
    }
}

void Regular_user::print_specific_playlist(string playlist_name)
{
    for(int i=0; i < playlists.size(); i++)
    {
        if(playlists[i].is_name_equal_to_title(playlist_name))
        {
            playlists[i].print_musics();
            return;
        }
    }

    throw Not_found_ex();
}

bool Regular_user::is_music_liked(Music *music)
{
    for(int i=0; i < liked_musics.size(); i++)
    {
        if(liked_musics[i] == music)
            return true;
    }

    return false;
}

Regular_user::Regular_user(string name_, string password_, int id_, string mode_)
    :User(name_, password_, id_, mode_){} 