#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

/*
* Text clock
! a < b ? x:y == statement ? ifTrue:ifFalse
*/

int moonPhase(int Yr, int Mth, int Dy){
    //! Refer to https://www.subsystems.us/uploads/9/8/9/4/98948044/moonphase.pdf
    //int A,B,C, daySince, sinceNewMoon, dayReal;
    //float cycleDay;
    //long double finalNum;
    int A, B, C, E, F, sinceNew;
    float numNew, lastNew;
    long double justDays;
    
    A = Yr/100;
    B = A/4;
    C = 2-A+B;
    E = 365.25 * (Yr+4716);
    F = 30.6001 * (Mth+1);
    justDays = C+Dy+E+F-1524.5;

    sinceNew = (justDays-2451549.5);
    numNew = sinceNew/29.53;
    lastNew = (numNew-floor(numNew))*29.53;

    return lastNew;
}

string dayWord(int gDay){

    string dayWrd;

    switch (gDay)
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
    return dayWrd;
}

string monthWord(int mDay){
    
    string monthWrd;

    switch (mDay)
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
    return monthWrd;
}

int main()
{
    int prevSec = 0;

    while (true)
    {
        int sec, min, hour, hourTw;
        int day,month,year;
        string am_pm, monthWrd;

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




        if (sec == prevSec+1 || (prevSec == 59 && sec ==0))
        {
            system("clear");
            
            cout << "It is the " << day << dayWord(day) << " of " << monthWord(month) << ", " << year << endl;
            cout << "The Time in 12Hr:\t" <<
            (hourTw < 10 ? "0":"") << hourTw << ":" << //? Add a 0 if
            (min<10 ? "0":"") << min << ":" <<    //? its less than 10 (01,02)
            (sec<10 ? "0":"") << sec << " " << am_pm << endl;

            cout << "The Time in 24Hr:\t" <<
            (hour < 10 ? "0":"") << hour << ":" <<
            (min<10 ? "0":"") << min << ":" <<
            (sec<10 ? "0":"") << sec << endl;

            int moomPhase = moonPhase(year, month, day);
            cout << moomPhase << " days since new Moon."  
            <<"\nNext one is in "<< 29 - moomPhase << " days." << endl;

        }
        prevSec = sec;
    }

    return 0;
}