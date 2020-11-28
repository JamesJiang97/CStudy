#include <iostream>
#include <cstdio>

using namespace std;

int MaxSubA(int *N, int size)
{
    int thisSub = 0, maxSub = 0;
    for (int i = 0; i < size; i++)
    {
        thisSub += N[i];
        if (thisSub < 0)
        {
            thisSub = 0;
        }
        if (thisSub > maxSub)
        {
            maxSub = thisSub;
        }
    }
    return maxSub;
}

int main()
{
    int n;
    cin >> n;
    int N[n];
    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }
    int m = MaxSubA(N, n);
    cout << m;
}