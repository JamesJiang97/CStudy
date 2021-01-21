#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>

#define A 1.4890924 // semimajor axis
#define B 1.4064796 // semiminor axis

using namespace std;

//LR = semimajor axis  UD = semiminor axis
double L, R, U = 0, D = -10;

void Ls(double x, double xn, double y, double yn)
{
    if (y > 0 && yn < y && U < 0.01)
    {
        U = y;
    }
    if (x < 0 && y >= 0 && yn <= 0)
    {
        L = x;
    }
    if (y < 0 && yn > y && D < -9)
    {
        D = y;
    }
}

int main()
{
    ofstream la("la.dat");
    ofstream sa("sa.dat");
    //ofstream eu("eu1.dat");

    for (int n = 50; n <= 3000; n += 10)
    {
        double vx = 0, vy = 1.63, x = 0.5, y = 0, t = 0, dt = 0.005;
        double r = sqrt(x * x + y * y);
        double r3 = r * r * r;
        double xn, yn;
        R = x;

        //eu << x << " " << y << endl;

        for (int i = 1; i < 100000; i++)
        {
            vx = vx - (x / r3) * dt;
            vy = vy - (y / r3) * dt;
            xn = x + vx * dt;
            yn = y + vy * dt;
            Ls(x, xn, y, yn);
            x = xn;
            y = yn;
            r = sqrt(x * x + y * y);
            r3 = r * r * r;
            //eu << x << " " << y << endl;
        }
        double La = fabs((R - L - A)/A);     // semimajor axis
        double Sa = fabs((U - D - B)/B);     // semiminor axis
        la << n << " " << La << endl;
        sa << n << " " << Sa << endl;
        U = 0, D = -10;
    }
}