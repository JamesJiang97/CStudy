#include <iostream>
#include <cstdio>
#include <cmath>
#include <random>

using namespace std;

mt19937_64 g(time(0));

double nDimBall(int dim)
{
    double axis[dim], rp = 0;
    for (int i = 0; i < dim; i++)
    {
        axis[i] = (g() / (mt19937_64::max() + 0.0));
        rp += axis[i] * axis[i];
    }
    return rp;
}

int main()
{
    //cout << mt19937_64::max()<< endl;
    int ntry, dim, r;
    double V, ncount = 0.0;
    cout << "Input values shall be positive integers \n"
         << "dimension = " << endl;
    cin >> dim;
    cout << "radius = " << endl;
    cin >> r;
    cout << "ntry = " << endl;
    cin >> ntry;
    int p = pow(2, dim);
    int m = pow(r, dim);
    for (int i = 1; i <= ntry; i++)
    {
        double rp = nDimBall(dim);
        if (rp <= 1)
        {
            ncount += 1.0;
        }
        V = (ncount / i) * p * m;
        cout << i << " " << V << endl;
    }
}