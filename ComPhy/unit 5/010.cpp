#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define RAND() (double(rand() / pow(2, 31)))

int main()
{
    int ntry;
    double V, ncount = 0.0;
    cout << "ntry=" << endl;
    cin >> ntry;
    for (int i = 1; i <= ntry; i++)
    {
        double x = RAND();
        double y = RAND();
        double z = RAND();
        if (x*x + y*y + z*z <= 1)
        {
            ncount += 1.0;
        }
        V = (ncount/i)*8;
        cout << i << " " << V << endl;
    }
}