#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

class Time
{
public:
    Time() {}

    time_t toTime(string time)
    {
        stringstream ss(time);
        string d, m, y;

        getline(ss, d, '/');
        getline(ss, m, '/');
        getline(ss, y, '/');
        struct tm a;
        try
        {
            a = {0, 0, 0, stoi(d), stoi(m) - 1, stoi(y) - 1900};
        }
        catch (const std::exception &e)
        {
            cout << time << endl;
        }

        time_t newTime = mktime(&a);
        return newTime;
        // struct tm *newTime = localtime(&x);
        // char s[100];
        // strftime(s, 100, "%d %m %y", newTime);
        // printf(s);
    }

    int checkDifTime(string time1, string time2)
    {
        time_t x = toTime(time1);
        time_t y = toTime(time2);
        if (x != (time_t)(-1) && y != (time_t)(-1))
        {
            double difference = difftime(y, x) / (60 * 60 * 24);
            return difference;
        }
        return 0;
    }

    friend class Member;
    friend class House;
    friend class System;
};