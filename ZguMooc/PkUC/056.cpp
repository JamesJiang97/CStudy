#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n, ka = 0, ko = 0;
    cin >> n;
    int N[n], O[n];
    char P[n][15], aP[n][15], oP[n][15];
    for (int i = 0; i < n; i++)
    {
        cin >> P[i] >> N[i];
        if (N[i] >= 60)
        {
            O[ko] = N[i];
            strcpy(oP[ko], P[i]);
            ko++;
        }
        else
        {
            strcpy(aP[ka], P[i]);
            ka++;
        }
    }
    for (int i = ko - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (O[j] < O[j + 1])
            {
                int tem = O[j + 1];
                O[j + 1] = O[j];
                O[j] = tem;
                char ctem[1][15];
                strcpy(ctem[0], oP[j + 1]);
                strcpy(oP[j + 1], oP[j]);
                strcpy(oP[j], ctem[0]);
            }
        }
    }
    for (int i = 0; i < ko; i++)
    {
        cout << oP[i] << endl;
    }
    for (int i = 0; i < ka; i++)
    {
        cout << aP[i] << endl;
    }
}