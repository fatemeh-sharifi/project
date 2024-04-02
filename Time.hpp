#ifndef TIME_HPP_INCLUDE
#define TIME_HPP_INCLUDE
#include <iostream>
#include <vector>
#include "string_functions.hpp"
#include "Errors.hpp"
using namespace std;

class Time
{
    public:
        Time(){}
        Time(string time);
        Time(int second, int minute, int hour);

        Time& operator+=(const Time t);
        Time& operator-=(const Time t);
        void print();
    
    private:
        int second;
        int minute;
        int hour;
};

#endif