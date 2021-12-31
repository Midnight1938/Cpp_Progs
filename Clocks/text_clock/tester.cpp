#include <iostream>
#include <cmath>
using namespace std;

/*
* A = Y/100 and then record the integer part                                            A = 20
* B = A/4 and then record the integer part                                              B = 5
* C = 2-A+B                                                                             C = -13
* E = 365.25 x (Y+4716) record the integer part                                         E = 2459228
* F = 30.6001 x (M+1) record the integer part                                           F = 122
* JD = C+D+E+F-1524.5                                                                   JD = 2457813.5
* last new moon:
* Day since New = 2457813.5 - 2451549.5 =                                               6264 days
* how many new moons there have been:
* New Moons = 6264 / 29.53 =                                                            212.123 cycles
* Now, multiply the fractional part by 29.53:
* Days into cycle = 0.123 x 29.53 =                                                     3.63 days since New Moon
*/

int main()
{
    float X = 12.345678;
    cout << X - floor(X) << endl;

    int A,B,C,E,F,New;
    float numNew,daysIn;
    long double JD;
    int D,M,Y;

    Y = 2021; M = 12; D = 31;

    A = Y/100;
    B = A/4;
    C = 2-A+B;
    E = 365.25 * (Y+4716);
    F = 30.6001*(M+1);

    JD = C+D+E+F-1524.5;

    New = JD- 2451549.5;
    numNew = New/29.53;
    daysIn = (numNew-floor(numNew)) * 29.53;

    cout << "Numbers: " << endl;
    cout << "A " << A << endl;
    cout << "B " << B << endl;
    cout << "C " << C << endl;
    cout << "E " << E << endl;
    cout << "F " << F << endl;
    cout << "JD " << JD << endl;
    cout << "since new " << New << endl;
    cout << "cycles " << numNew << endl;
    cout << "days since " << daysIn << endl;

    return 0;
}