#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <ctime>
#include <random>
#include <chrono>

using namespace std;

#define RAND() (double(rand() / (RAND_MAX + 1.0)));

int main()
{
    int i, ntry;
    double x, y, pi, ncout = 0.0;
    ofstream sf("xy.txt");
    cout << "ntry = ?" << endl;
    cin >> ntry;
    mt19937_64 g(time(0));
    for (i = 1; i <= ntry; ++i)
    {
        x = g() / (mt19937_64::max() + 0.0);
        y = g() / (mt19937_64::max() + 0.0);
        //x = RAND();
        //y = RAND(); 
        sf << x << " " << y << endl;
        if (x * x + y * y <= 1)
        {
            ncout += 1.0;
        }
        pi = (ncout / i) * 4;
        cout << i << " " << pi << endl;
    }
}