#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double n, a, b, c, d;
    int y;
    a = b = c = d = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> y;
        if (y <= 18)
        {
            a += 1.0;
        }
        else if (y <= 35)
        {
            b += 1.0;
        }
        else if (y <= 60)
        {
            c += 1.0;
        }
        else
        {
            d += 1.0;
        }
    }
    printf("%.2f%\n%.2f%\n%.2f%\n%.2f%\n", a/n*100, b/n*100, c/n*100, d/n*100);
}