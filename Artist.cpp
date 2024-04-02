#include "Artist.hpp"
#include "consts.hpp"

void Artist::print_info_short()
{
    cout << id << DIVIDER;
    cout << mode << DIVIDER;
    cout << name << DIVIDER;
    cout << musics.size() << endl;
}

void Artist::print_all_info()
{
    print_common_info();
    cout << SONGS;
    for(int i=0; i < musics.size(); i++)
    {
        if(i == musics.size() - 1)
        {
            musics[i]->print_title();
            cout << endl;
            break;
        }

        musics[i]->print_title();
        cout << DIVIDER;
    }

    if(musics.size() == 0)
    {
        cout << endl;
    }
}

void Artist::print_registered_music()
{
    if(musics.size() == 0)
    {
        throw Empty_ex();
    }
    
    cout << MUSIC_INFO_COLUMNS << endl;
    for(int i=0; i < musics.size(); i++)
    {
        musics[i]->print_all_info();
    }
}

void Artist::delete_music(int id_)
{
    for(int i=0; i < musics.size(); i++)
    {
        if(musics[i]->is_id_for_this_music(id_))
        {
            musics.erase(musics.begin() + i);
        }
    }
}

bool Artist::is_music_for_artist(Music *music)
{
    for(int i=0; i < musics.size(); i++)
    {
        if(musics[i] == music)
        {
            return true;
        }
    }

    return false;
}

Artist::Artist(string name_, string password_, int id_, string mode_)
    :User(name_, password_, id_, mode_){}    
    
void Artist::add_music(Music *music)
{
    musics.push_back(music);
}