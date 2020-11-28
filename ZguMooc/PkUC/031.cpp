#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int L, M, b, e, x = 0;
    cin >> L >> M;
    int l[L+1];
    for (int i = 0; i < L + 1; i++)
    {
        l[i] = 1;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> b >> e;
        for (int i = b; i <= e; i++)
        {
            l[i] = 0;
        }
    }
    for (int i = 0; i < L + 1; i++)
    {
        if(l[i]){x++;}
    }
    cout << x;
}