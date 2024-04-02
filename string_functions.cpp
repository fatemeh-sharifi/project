#include "string_functions.hpp"

const char LEFT_ARG = '<';
const char RIGHT_ARG = '>';
const char SPACE = ' ';

bool is_number(string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] > '9' || str[i] < '0')
        {
            return false;
        }
    }

    return true;
}

vector<string> split_line(string line)
{
    vector<string> result;
    for(int i=0; i < line.size(); i++)
    {
        string str = "";

        if(line[i] == LEFT_ARG)
        {
            while(line[i] != RIGHT_ARG && i < line.size())
            {
                str += line[i];
                i++;
            }

            if(i < line.size())
            {
                if(line[i] == RIGHT_ARG)
                    str += line[i];
            }        

            result.push_back(str);
            i++;
            continue;
        }

        while(line[i] != SPACE && i < line.size())
        {
            str += line[i];
            i++;
        }

        result.push_back(str);
    }

    return result;
}

string take_arg(string arg)
{
    string result = "";
    if(arg[0] == LEFT_ARG && arg[arg.size()-1] == RIGHT_ARG)
    {
        result = arg.substr(1, arg.size()-2);
    }

    return result;
}

vector<string> split_string_by_char(string str, char divider)
{
    vector<string> result;
    for(int i=0; i < str.size(); i++)
    {
        string word = "";

        while(str[i] != divider && i < str.size())
        {
            word += str[i];
            i++;
        }

        result.push_back(word);
    }

    return result;   
}