#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string timeFormat(long int seconds)
{
    string timeString;
    int mm{0};
    int hh{0};
    float ss;
    mm = floor(seconds / 60);
    ss = ((seconds / 60.0) - mm) * 60;
    while (mm > 59)
    {
        mm = mm - 60;
        hh++;
    }

    std::stringstream hhs, mms, sss;
    hhs << std::setw(2) << std::setfill('0') << hh;
    mms << std::setw(2) << std::setfill('0') << mm;
    sss << std::setw(2) << std::setfill('0') << ss;

    timeString = hhs.str() + ":" + mms.str() + ":" + sss.str();

    return timeString;
}

int main()
{
    long int sec = 3612;
    string output = timeFormat(sec);
    std::cout << output << "\n";
}