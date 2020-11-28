#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, m, x = 0;
    cin >> n;
    int l[n];
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        if (l[i] == m)
        {
            x++;
        }
    }
    cout << x;
}