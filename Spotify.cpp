#include "Spotify.hpp"
#include <algorithm>

Music* Spotify::find_music_by_id(int id)
{
    for(int i=0; i < musics.size(); i++)
    {
        if(musics[i]->is_id_for_this_music(id))
        {
            return musics[i];
        }
    }

    return NULL;
}

int Spotify::find_music_index(Music *music)
{
    for(int i=0; i < musics.size(); i++)
    {
        if(musics[i] == music)
        {
            return i;
        }
    }

    throw Bad_req_ex();
}


void Spotify::add_user(string username, string password, string mode)
{   
    if(find_loged_in_user() != NULL)
        throw Permission_denied_ex();

    if(mode == "" || password == "" || username == "")
        throw Bad_req_ex();
    
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i]->is_name_equal_to_username(username))
            throw Bad_req_ex();
    }

    if(mode == ARTIST)
    {
        Artist *artist = new Artist(username, password, users.size() + 1, mode);
        users.push_back(artist);           
    }

    else if(mode == REGULAR_USER)
    {
        Regular_user *user = new Regular_user(username, password, users.size() + 1, mode);
        users.push_back(user);
    }

    else
        throw Bad_req_ex(); 
}

User* Spotify::find_user_by_name(string name)
{
    User* user = NULL;
    for(int i=0; i < users.size(); i++)
    {
        if(users[i]->is_name_equal_to_username(name))
        {
            user = users[i];
            break;
        }
    }

    return user;
}

void Spotify::login(string username, string password)
{
    if(find_loged_in_user() != NULL)
        throw Permission_denied_ex();

    if(username == "" || password == "")
        throw Bad_req_ex();

    if(find_user_by_name(username) == NULL)
        throw Not_found_ex();

    if(find_user_by_name(username)->log_in(password))
        return;

    throw Permission_denied_ex();
}

User* Spotify::find_loged_in_user()
{
    for(int i=0; i < users.size(); i++)
    {
        if(users[i]->is_loged_in())
            return users[i];
    }

    return NULL;
}

void Spotify::logout_user(vector<string>& command)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    find_loged_in_user()->log_out();
    cout << OK << endl;
    return;
}

void Spotify::add_playlist_user(vector<string>& command)
{
    string name = "";
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    if(!find_loged_in_user()->is_user_regular())
        throw Permission_denied_ex();

    for(int i = 0; i + 1 < command.size(); i++)
    {   
        if(command[i] == NAME)
        {
            name = take_arg(command[i+1]);
        }
    }

    if(name == "")
        throw Bad_req_ex();

    if(!find_loged_in_user()->add_playlist(name))
        throw Bad_req_ex();

    cout << OK << endl;
}

void Spotify::print_all_users()
{
    if(users.size() == 0)
        throw Empty_ex();

    cout << USER_INFO_COLUMNS << endl;
    for(int i=0; i < users.size(); i++)
    {
        users[i]->print_info_short();
    }
}

User* Spotify::find_user_by_id(int id)
{
    for(int i = 0; i < users.size(); i++)
    {
        if(users[i]->is_num_equal_to_id(id))
        {
            return users[i];
        }
    }

    return NULL;   
}

void Spotify::print_specific_user(int id)
{
    if(find_user_by_id(id) == NULL)
        throw Not_found_ex();

    find_user_by_id(id)->print_all_info();           
}

void Spotify::print_users_info(vector<string>& command)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    int id;
    for(int i = 0; i < command.size(); i++)
    {   
        if(command[i] == ID)
        {
            try
            {
                if(!is_number(take_arg(command[i+1])))
                    throw Bad_req_ex();

                id = stoi(take_arg(command[i+1]));
                print_specific_user(id);
                return;
            }
            
            catch(Not_found_ex &ex)
            {
                throw;
            }

            catch(...)
            {
                throw Bad_req_ex();
            }    
        }
    }

    print_all_users();
}

void Spotify::print_musics_info(vector<string>& command)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    int id;
    for(int i = 0; i < command.size(); i++)
    {   
        if(command[i] == ID)
        {
            try
            {
                if(!is_number(take_arg(command[i+1])))
                    throw Bad_req_ex();

                id = stoi(take_arg(command[i+1]));
                print_specific_music(id);
                return;
            }
            
            catch(Not_found_ex &ex)
            {
                throw;
            }

            catch(...)
            {
                throw Bad_req_ex();
            }    
        }
    }

}

void Spotify::print_specific_music(int id)
{
    if(find_music_by_id(id) == NULL)
        throw Not_found_ex();

    cout << ONE_MUSIC_INFO_COLUMS << endl;
    find_music_by_id(id)->print_all_info();
}


void Spotify::add_music(string title, string path, string year_str, string album, string tags_ent, string duration)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    if(!find_loged_in_user()->is_user_artist())
        throw Permission_denied_ex();
    
    if(!is_number(year_str))
        throw Bad_req_ex();

    int year = stoi(year_str);    
    vector<string> tags = split_string_by_char(tags_ent, TAG_DIVIDER);


    Music *music = new Music(last_music_id, title, path, duration, album, year, tags, find_loged_in_user()->get_name());
    last_music_id ++;
    musics.push_back(music);
    find_loged_in_user()->add_music(music);
}

void Spotify::get_registered_music_artist()
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    if(!find_loged_in_user()->is_user_artist())
        throw Permission_denied_ex();

    find_loged_in_user()->print_registered_music();
}

void Spotify::delete_music(vector<string>& command)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    if(!find_loged_in_user()->is_user_artist())
        throw Permission_denied_ex();

    int id = NOT_INITIALIZED;  

    if(id == NOT_INITIALIZED)
        throw Bad_req_ex();

    if(find_music_by_id(id) == NULL)
        throw Not_found_ex();

    if(!find_loged_in_user()->is_music_for_artist(find_music_by_id(id)))
        throw Permission_denied_ex();

    for(int i=0; i < users.size(); i++)
    {
        users[i]->delete_music(id);
    }

    int index = find_music_index(find_music_by_id(id));
    delete find_music_by_id(id);
    musics.erase(musics.begin() + index);
    cout << OK << endl;
}

void Spotify::add_music_to_playlist(vector<string>&  command)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    if(!find_loged_in_user()->is_user_regular())
        throw Permission_denied_ex();

    string playlist_name;
    int id;
    for(int i = 0; i < command.size(); i++)
    {   
        try
        {
            if(command[i] == NAME)
            {
                playlist_name = take_arg(command[i+1]);
            }

            if(command[i] == ID)
            {
                if(!is_number(take_arg(command[i+1])))
                    throw Bad_req_ex();

                id = stoi(take_arg(command[i+1]));
            }  

        }catch(...)
        {
            throw Bad_req_ex();
        }
    }   

    if(playlist_name == "")
        throw Bad_req_ex();

    if(find_music_by_id(id) == NULL)
        throw Not_found_ex();

    find_loged_in_user()->add_music_to_playlist((find_music_by_id(id)), playlist_name);
    cout << OK << endl;        
}

void Spotify::search_music(vector<string>& command)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    if(!find_loged_in_user()->is_user_regular())
        throw Permission_denied_ex();

    string artist_name = "", music_name = "", tag = "";
    for(int i = 0; i+1 < command.size(); i++)
    { 
        if(command[i] == NAME)
        {
            artist_name = take_arg(command[i+1]);
        }

        if(command[i] == ARTIST)
        {
            music_name = take_arg(command[i+1]);
        }

        if(command[i] == TAG) 
        {
            tag = take_arg(command[i+1]);
        }
    }

    vector<Music*> search_result;
    for(int i=0; i < musics.size(); i++)
    {
        if(musics[i]->is_music_searched(artist_name, music_name, tag))
            search_result.push_back(musics[i]);
    }

    if(search_result.size() == 0)
        throw Empty_ex();

    cout << ALL_MUSIC_INFO_COLUMNS << endl;
    for(int i=0; i < search_result.size(); i++)
    {
        search_result[i]->print_info_short();
        cout << endl;
    }    
}

void Spotify::print_playlists(vector<string>& command)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    if(!find_loged_in_user()->is_user_regular())
        throw Permission_denied_ex();

    string name = "";

    for(int i = 0; i + 1 < command.size(); i++)
    {   
        if(command[i] == NAME)
        {
            name = take_arg(command[i+1]);
        }
    }
    
    int id;
    if(id == NOT_INITIALIZED)
        throw Bad_req_ex();

    if(find_user_by_id(id) == NULL)
        throw Not_found_ex();

    if(find_user_by_id(id)->is_user_artist())
        throw Bad_req_ex();

    if(name == "")
    {
        find_user_by_id(id)->print_playlists();
        return;
    }    

    find_user_by_id(id)->print_specific_playlist(name);
}

void Spotify::follow_user(vector<string>& command)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();
    
    int id;
    if(id == NOT_INITIALIZED)
        throw Bad_req_ex();

    if(find_user_by_id(id) == NULL)
        throw Not_found_ex();

    if(find_user_by_id(id) == find_loged_in_user())
        throw Bad_req_ex();

    find_loged_in_user()->add_to_following(find_user_by_id(id));
    find_user_by_id(id)->add_to_followers(find_loged_in_user());
    cout << OK << endl;        
}

void Spotify::unfollow_user(vector<string>& command)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    int id;
    if(id == NOT_INITIALIZED)
        throw Bad_req_ex();

    if(find_user_by_id(id) == NULL)
        throw Not_found_ex();

    if(find_user_by_id(id) == find_loged_in_user())
        throw Bad_req_ex();

    find_loged_in_user()->remove_from_following(find_user_by_id(id));
    find_user_by_id(id)->remove_from_followers(find_loged_in_user());
    cout << OK << endl;
}

void Spotify::delete_playlist(vector<string>& command)
{
    string name = "";
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    if(!find_loged_in_user()->is_user_regular())
        throw Permission_denied_ex();

    for(int i = 0; i + 1 < command.size(); i++)
    {   
        if(command[i] == NAME)
        {
            name = take_arg(command[i+1]);
        }
    }

    if(name == "")
        throw Bad_req_ex(); 

    find_loged_in_user()->delete_playlist(name);      
    cout << OK << endl;
}

void Spotify::like_music(vector<string>& command)
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    if(!find_loged_in_user()->is_user_regular())
        throw Permission_denied_ex();   

    int id = NOT_INITIALIZED;
    
   
    if(id == NOT_INITIALIZED)
        throw Bad_req_ex();

    if(find_music_by_id(id) == NULL)
        throw Not_found_ex();

    find_loged_in_user()->like_music(find_music_by_id(id));
    cout << OK << endl;
}

void Spotify::print_liked_musics()
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    find_loged_in_user()->print_liked_musics();
}

bool compare_musics_like(Music *m1, Music *m2)
{
    if(m1->get_likes_count() != m2->get_likes_count())
        return m1->get_likes_count() > m2->get_likes_count();

    return m1->get_id() < m2->get_id();    
}

void Spotify::show_recommendations()
{
    if(find_loged_in_user() == NULL)
        throw Permission_denied_ex();

    if(!find_loged_in_user()->is_user_regular())    
        throw Permission_denied_ex();

    sort(musics.begin(), musics.end(), compare_musics_like);

    vector<Music*> recommendations;
    for(int i=0; i < musics.size(); i++)
    {
        if(recommendations.size() >= MAX_RECOMMENDED_MUSIC)
            break;

        if(musics[i]->get_likes_count() == 0)
            break;

        if(find_loged_in_user()->is_music_liked(musics[i]))
            continue;    

        recommendations.push_back(musics[i]);
    }

    sort(musics.begin(), musics.end(), [](Music *m1, Music *m2){return m1->get_id() < m2->get_id();});

    if(recommendations.size() == 0)
        throw Empty_ex();

    cout << RECOMMENDED_MUSICS_COLUMNS << endl;
    for(int i=0; i < recommendations.size(); i++)
    {
        recommendations[i]->print_as_recommended();
    }
}

Spotify::~Spotify()
{
    for(int i=0; i < users.size(); i++)
    {
        delete users[i];
    }

    for(int i=0; i < musics.size(); i++)
    {
        delete musics[i];
    }
}