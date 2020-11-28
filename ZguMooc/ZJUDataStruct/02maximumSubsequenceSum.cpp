#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int N[n];
    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }
    int thisSub = 0, maxSub = 0, tb = N[0], b = N[0], e = N[n-1];
    for (int i = 0; i < n; i++)
    {
        thisSub += N[i];
        if (thisSub == 0 && maxSub ==0){
            b = 0;
            e = 0;
        }
        if (thisSub < 0)
        {
            thisSub = 0;
            tb = N[i+1];
        }
        if (thisSub > maxSub)
        {
            maxSub = thisSub;
            e = N[i];
            b = tb;
        }
    }
    cout << maxSub << " " << b << " " << e << endl; 
}