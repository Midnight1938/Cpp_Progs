#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

/*
* Text clock
! a < b ? x:y == statemet ? ifTrue:ifFalse
*/

int moonPhase(int Yr, int Mth, int Dy){
    //! Refer to https://www.subsystems.us/uploads/9/8/9/4/98948044/moonphase.pdf
    //int A,B,C, daySince, sinceNewMoon, dayReal;
    //float cycleDay;
    //long double finalNum;
    int A, B, C, E, F, New;
    float numNew, daysIn;
    long double JD;
    
    A = Yr/100;
    B = A/4;
    C = 2-A+B;
    E = 365.25 * (Yr+4716);
    F = 30.6001 * (Mth+1);
    JD = C+Dy+E+F-1524.5;

    New = (JD-2451549.5);
    numNew = New/29.53;
    daysIn = (numNew-floor(numNew))*29.53;

    return daysIn;
}

int main()
{
    int prevSec = 0;

    while (true)
    {
        int sec, min, hour, hourTw;
        int day,month,year;
        string am_pm, monthWrd, dayWrd;

        //* Get the time the C way
        time_t totalSec = time(0);
        struct tm *ctim = localtime(&totalSec);

        sec = ctim->tm_sec;
        min = ctim->tm_min;
        hour = ctim->tm_hour;

        day = ctim -> tm_mday;
        month = 1 + ctim->tm_mon;
        year = 1900 + ctim->tm_year;

        if (hour >= 12)
        {am_pm = "PM";}
        else {am_pm = "AM";}
        hourTw = hour > 12 ? hour - 12 : hour; //? 12 hour clock

        switch (month)
        {
        case 1:         monthWrd = "January";   break;
        case 2:         monthWrd = "Febuary";   break;
        case 3:         monthWrd = "March";     break;
        case 4:         monthWrd = "April";     break;
        case 5:         monthWrd = "May";       break;
        case 6:         monthWrd = "June";      break;
        case 7:         monthWrd = "July";      break;
        case 8:         monthWrd = "August";    break;
        case 9:         monthWrd = "September"; break;
        case 10:        monthWrd = "October";   break;
        case 11:        monthWrd = "November";  break;
        case 12:        monthWrd = "December";  break;

        default:        monthWrd = "a month";
        }

        switch (day)
        {
        case 1:
        case 21:
        case 31:        dayWrd = "st";  break;
        case 2:
        case 22:        dayWrd = "nd";  break;
        case 3:
        case 23:        dayWrd = "rd";  break;

        default:        dayWrd = "th";  break;  
        }

        if (sec == prevSec+1 || (prevSec == 59 && sec ==0))
        {
            system("clear");
            
            cout << "It is the " << day << dayWrd << " of " << monthWrd << ", " << year << endl;
            cout << "The Time in 12Hr:\t" <<
            (hourTw < 10 ? "0":"") << hourTw << ":" << //? Add a 0 if
            (min<10 ? "0":"") << min << ":" <<    //? its less than 10 (01,02)
            (sec<10 ? "0":"") << sec << " " << am_pm << endl;

            cout << "The Time in 24Hr:\t" <<
            (hour < 10 ? "0":"") << hour << ":" <<
            (min<10 ? "0":"") << min << ":" <<
            (sec<10 ? "0":"") << sec << endl;

            cout << moonPhase(year, month, day) << " since new Moon." << endl;

        }
        prevSec = sec;
    }

    return 0;
}