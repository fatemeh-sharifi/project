#include "Playlist.hpp"
const string PRINT_PLAYLIST_DIVIDER = ", ";
const string PRINT_MUSICS_COLUMNS = "ID, Name, Artist";

Playlist::Playlist(string name_)
{
    name = name_;
    duration = Time(INIT_TIME);
}

bool Playlist::is_name_equal_to_title(string str)
{
    if(name == str)
    {
        return true;
    }

    return false;
}

void Playlist::add_music(Music *music)
{
    musics.push_back(music);
    duration += music->get_duration();
}

void Playlist::delete_music(int id)
{
    for(int i=0; i < musics.size(); i++)
    {
        if(musics[i]->is_id_for_this_music(id))
        {
            duration-=musics[i]->get_duration();
            musics.erase(musics.begin() + i);
        }
    }
}

void Playlist::print_info()
{
    cout << name << PRINT_PLAYLIST_DIVIDER;
    cout << musics.size() << PRINT_PLAYLIST_DIVIDER;
    duration.print();
    cout << endl;
}

void Playlist::print_musics()
{
    if(musics.size() == 0)
        throw Empty_ex();

    cout << PRINT_MUSICS_COLUMNS << endl;
    for(int i=0; i < musics.size(); i++)
    {
        musics[i]->print_info_short();
        cout << endl;
    }
}