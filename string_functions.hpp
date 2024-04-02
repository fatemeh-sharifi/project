#ifndef STRING_FUNCTIONS_HPP_INCLUDE
#define STRING_FUNCTIONS_HPP_INCLUDE

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_number(string str);
vector<string> split_line(string line);
string take_arg(string arg);
vector<string> split_string_by_char(string str, char divider);

#endif