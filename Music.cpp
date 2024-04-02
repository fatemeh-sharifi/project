#include "Music.hpp"
#include "Errors.hpp" 
#include "consts.hpp"
#include <cstring>

void Music::print_info_short()
{
    cout << id << PRINT_DIVIDER;
    cout << title << PRINT_DIVIDER;
    cout << artist;
}

void Music::print_as_recommended()
{
    print_info_short();
    cout << PRINT_DIVIDER << likes_count;
    cout << endl;
}

void Music::print_all_info()
{
    cout << id << PRINT_DIVIDER;
    cout << title << PRINT_DIVIDER;
    cout << artist << PRINT_DIVIDER;
    cout << year << PRINT_DIVIDER;
    cout << album << PRINT_DIVIDER;
    for(int i=0; i < tags.size(); i++)
    {
        cout << tags[i];
        if(i != tags.size()-1)
        {
            cout << PRINT_TAGS_DIVIDER;
        }
    }

    cout << PRINT_DIVIDER;
    duration.print();
    cout << endl;
}

bool Music::is_id_for_this_music(int num)
{
    if(id == num)
    {
        return true;
    }

    return false;
}

bool Music::is_music_searched(string name, string artist_name, string tag)
{
    bool is_tag_found = false;
    for(int i=0; i < tags.size(); i++)
    {
        if(tags[i] == tag)
        {
            is_tag_found = true;
        }
    }

    if(strstr(this->title.c_str(), name.c_str()) && strstr(this->artist.c_str(), artist_name.c_str()) && (is_tag_found || tag == ""))
    {
        return true;
    }

    return false;
}

Music::Music(int id_, string title_, string path_, string time_, string album_, int year_, vector<string> tags_, string artist_)
    :duration(time_)
{
    id = id_;
    title = title_;
    path = path_;
    album = album_;
    year = year_;
    tags = tags_;
    artist = artist_;
}