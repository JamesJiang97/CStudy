#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int l[10], t, x = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> l[i];
    }
    cin >> t;
    for (int i = 0; i < 10; i++)
    {
        if (l[i] <= t + 30)
        {
            x++;
        }
    }
    cout << x;
}
