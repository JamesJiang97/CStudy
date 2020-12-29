#include <iostream>
#include <cstdio>
#include <cmath>
#include <random>
#include <fstream>

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

double nDBA(double dim, double r)
{
    double fDim = dim / 2 + 1;
    double ga = tgamma(fDim);
    double pi = M_PI;
    double V = (pow(pi, dim / 2) / ga) * pow(r, dim);
    return V;
}

int main()
{
    //cout << mt19937_64::max()<< endl;
    int ntry, dim;
    double A, Alog, V, Vp = 0, r, ncount = 0.0;
    cout << "Input values shall be positive integers \n"
         << "dimension = " << endl;
    cin >> dim;
    cout << "radius = " << endl;
    cin >> r;
    cout << "ntry = " << endl;
    cin >> ntry;
    int p = pow(2, dim);
    double m = pow(r, dim);
    ofstream asf("A.dat");
    ofstream alsf("Alog.dat");
    double Va = nDBA(dim, r);
    for (int i = 1; i <= ntry; i++)
    {
        double rp = nDimBall(dim);
        if (rp <= 1) ncount += 1.0;
        V = (ncount / i) * p * m;
        A = fabs((V - Va) / Va);
        Alog = log(fabs((V - Va) / Va));
        if (i >= 100000)
        {
            asf << i << " " << A << endl;
            alsf << i << " " << Alog << endl;
        }
    }
    cout << "数値解：" << V << endl;
    cout << "解析解：" << Va << endl;
}