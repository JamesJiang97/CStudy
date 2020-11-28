#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define RAND() (double(rand()/ pow(2, 31)))

int main()
{
    int ntry;
    double S, ncount = 0.0;
    cout << "ntry=" << endl;
    cin >> ntry;
    for (int i = 1; i <= ntry; i++)
    {
        double x = RAND() * 3;
        double y = RAND() * 9;
        double fx = x * x;
        if (y <= fx)
        {
            ncount+= 1.0;
        }
        S = (ncount / i)*27;
        cout << i << " " << S << endl;
    }
}