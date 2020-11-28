#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int A[5][5], Max = -32768, Min = 32767, Maxi, Maxj, Mini, Minj;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (A[i][j] > Max)
            {
                Max = A[i][j];
                Maxi = i; Maxj =j;
            }
        }
        for (int j = 0; j < 5; j++)
        {
            if (A[i][j] == Max)
            {
                for (int m = 0; m < 5; m++)
                {
                    if (A[m][j] < Min)
                    {
                        Min = A[m][j];
                        Mini = m; Minj = j;
                    }
                }
                if(Maxi == Mini && Maxj == Minj){
                    cout << Maxi + 1 << " " << Maxj + 1 << " " << Max;
                    return 0;
                }
            }
        }
        Max = -32768, Min = 32767;
    }
    cout << "not found";
}
