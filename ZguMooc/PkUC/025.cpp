#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int x[3], y[3];
    for (int i = 81; i < 343; i++)
    {
        int xi = i, yi = i;
        for (int n = 0; n < 3; n++)
        {
            x[n] = xi % 7;
            xi /= 7;
        }
        for (int n = 0; n < 3; n++)
        {
            y[n] = yi % 9;
            yi /= 9;
        }
        if (x[0] == y[2] && x[1] == y[1] && x[2] == y[0])
        {
            cout << i << endl;
            for (int n = 2; n >= 0; n--)
            {
                cout << x[n];
            }
            cout << endl;
            for (int n = 2; n >= 0; n--)
            {
                cout << y[n];
            }
            return 0;
        }
    }
}