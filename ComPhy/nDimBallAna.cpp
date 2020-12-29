#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

double nDBA(double dim, double r)
{
    double fDim = dim / 2 + 1;
    double ga = tgamma(fDim);
    double pi = M_PI;
    double V = (pow(pi, dim / 2) / ga) * pow(r, dim);
    return V;
}

/*  int main()
{
    double dim, r;
    cin >> dim >> r;
    double fDim = dim / 2 + 1;
    double ga = tgamma(fDim);
    double pi = M_PI;
    double V = (pow(pi, dim / 2) / ga) * pow(r, dim);
    cout << setprecision(10) << V;
} */