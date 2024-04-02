#include "Time.hpp"
#include "consts.hpp"

Time::Time(string time)
{
    string second_ = "", minute_ = "", hour_ = ""; 
    try
    {
        if(time.size() != TIME_STRING_SIZE || time[TIME_DIVIDER_INDEX_ONE] != TIME_DIVIDER || time[TIME_DIVIDER_INDEX_TWO] != TIME_DIVIDER)
        {
            throw Bad_req_ex();
        }

        hour_ += time[HOUR_FIRST_INDEX];
        hour_ += time[HOUR_FIRST_INDEX+1];
        minute_ += time[MINUTE_FIRST_INDEX];
        minute_ += time[MINUTE_FIRST_INDEX+1];
        second_ += time[SECOND_FIRST_INDEX];
        second_ += time[SECOND_FIRST_INDEX+1];

        if(!is_number(hour_) || !is_number(minute_) || !is_number(second_))
            throw Bad_req_ex();

        this->hour = stoi(hour_);
        this->minute = stoi(minute_);
        this->second = stoi(second_);
        if(second > MAX_MINUTE_SECOND || minute > MAX_MINUTE_SECOND)
            throw Bad_req_ex();
    }

    catch(...)
    {
        throw Bad_req_ex();
    }
    
}

Time::Time(int second, int minute, int hour)
{
    if(second > MAX_MINUTE_SECOND || minute > MAX_MINUTE_SECOND)
    {
        throw Bad_req_ex();
    }

    this->second = second;
    this->minute = minute;
    this->hour = hour;
}

void Time::print()
{
   cout << hour/10 << hour%10 << TIME_DIVIDER;
   cout << minute/10 << minute%10 << TIME_DIVIDER;
   cout << second/10 << second%10; 
}

Time& Time::operator+=(const Time t)
{
    int s = (t.second + this ->second) % SIXTY;
    int m = ((this->minute + t.minute) + ((t.second + this ->second) / SIXTY)) % SIXTY;
    int h = (t.hour + this->hour) + (((this->minute + t.minute) + ((t.second + this ->second) / SIXTY)) / SIXTY);
    this->second = s;
    this->minute = m;
    this->hour = h;
    
    return *this;
}

Time& Time::operator-=(const Time t)
{
    int s, m, h;
    if(this->second - t.second < 0)
    {
        if(this->minute > 0)
        {
            this->minute -= 1;
            s = this ->second - t.second + SIXTY;
        }

        else
        {
            this->hour -= 1;
            this->minute += SIXTY - 1;
            s = this->second - t.second + SIXTY;
        }
    }

    else
    {
        s = this->second - t.second;
    }

    if(this->minute - t.minute < 0)
    {
        this->hour -= 1;
        m = this->minute - t.minute + SIXTY;       
    }

    else
    {
        m = this->minute - t.minute;
    }

    h = this->hour - t.hour;

    this->second = s;
    this->minute = m;
    this->hour = h;
    
    return *this;   
}