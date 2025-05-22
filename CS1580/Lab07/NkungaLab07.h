#ifndef NKUNGA
#define NKUNGA

#include <iostream>
using namespace std;

template <typename T1, typename T2>
bool compareASCII(T1 lhs, T2 rhs)
{
    char lhsChar = to_string(lhs).back();
    char rhsChar = to_string(rhs).back();

    if(abs(static_cast<int>(lhsChar) - static_cast<int>(rhsChar)) < 10)
    {
        return true;
    } else
    {
        return false;
    }
}

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

Time operator+(Time time1, Time time2);
Time operator-(Time time1, Time time2);
bool operator>(Time time1, Time time2);
std::ostream& operator<<(std::ostream& os, const Time& time);

#endif