//supersphere.C
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>


using namespace std;
//#define RAND() (float(rand() / pow(2, 31)))

mt19937_64 g(1);

int main(void)
{
    int i, j;
    double ncout = 0.0;
    int ntry;
    int dim;
    //float pole;
    float tmp = 0;
    float V;
    cout << "dim=?";
    cin >> dim;
    cout << "ntry=?";
    cin >> ntry;
    int p = pow(2, dim);
    for (i = 1; i <= ntry; ++i)
    {
        float tmp = 0;
        for (j = 1; j <= dim; ++j)
        {
            double pole = g() / (mt19937_64::max() + 0.0);
            tmp = tmp + pole * pole;
        }
        if (tmp <= 1)
        {
            ncout = ncout + 1.0;
        }
        V = (ncout / i) * p;
        cout << "i=" << i << " "
             << "V=" << V << "\n"; 
    }
}