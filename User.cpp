#include "User.hpp"
#include "consts.hpp"

User::User(string name_, string password_, int id_, string mode_)
{
    name = name_;
    password = password_;
    id = id_;
    mode =  mode_;
}

bool User::log_in(string password)
{
    if(this->password == password && loged_in == false)
    {
        loged_in = true;
        return true;
    }

    return false;
}

bool User::is_num_equal_to_id(int num)
{
    if(id == num)
    {
        return true;
    }

    return false;
}

bool User::is_name_equal_to_username(string str)
{
    if(name == str)
    {
        return true;
    }

    return false;
}

void User::log_out()
{
    loged_in = false;
}

void User::print_common_info()
{
    cout << ID_PRINT << id << endl;
    cout << MODE_PRINT << mode << endl;
    cout << USERNAME << name << endl;

    cout << FOLLOWINGS;
    for(int i=0; i<followings.size(); i++)
    {
        if(i != followings.size() - 1)
            cout << DIVIDER;
    }     
    cout << endl;

    cout << FOLLOWERS;
    for(int i=0; i<followers.size(); i++)
    {
        if(i != followers.size() - 1)
            cout << DIVIDER;
    }
    cout << endl;
}

int User::find_user_index_in_following(User *user)
{
    for(int i=0; i < followings.size(); i++)
    {
        if(followings[i] == user)
        {
            return i;
        }
    }

    return NOT_FOUND_AMOUNT;
}

int User::find_user_index_in_followers(User *user)
{
    for(int i=0; i < followers.size(); i++)
    {
        if(followers[i] == user)
        {
            return i;
        }
    }

    return NOT_FOUND_AMOUNT;
}

void User::remove_from_following(User *user)
{
    int user_index = find_user_index_in_following(user);

    if(user_index == NOT_FOUND_AMOUNT)
    {
        throw Bad_req_ex();
    }    

    followings.erase(followings.begin() + user_index);
}

void User::remove_from_followers(User *user)
{    
    int user_index = find_user_index_in_followers(user);
    if(user_index == NOT_FOUND_AMOUNT)
    {
        throw Bad_req_ex();
    }    

    followers.erase(followers.begin() + user_index);
}

void User::add_to_followers(User *user)
{
    if(find_user_index_in_followers(user) != NOT_FOUND_AMOUNT)
    {
        throw Bad_req_ex();
    }

    followers.push_back(user);
}

void User::add_to_following(User *user)
{
    if(find_user_index_in_following(user) != NOT_FOUND_AMOUNT)
    {
        throw Bad_req_ex();
    }

    followings.push_back(user);
}