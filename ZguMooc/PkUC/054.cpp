#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char N[n][25];
    int Sco[n];
    for (int i = 0; i < n; i++)
    {
        cin >> N[i] >> Sco[i];
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (Sco[j] < Sco[j + 1])
            {
                int tmp = Sco[j + 1];
                Sco[j + 1] = Sco[j];
                Sco[j] = tmp;
                char ctem[1][25];
                strcpy(ctem[0], N[j + 1]);
                strcpy(N[j + 1], N[j]);
                strcpy(N[j], ctem[0]);
            }
            else if (Sco[j] == Sco[j + 1])
            {
                for (int k = 0; k < 25; k++)
                {
                    int a = (int)N[j][k], b = (int)N[j + 1][k];
                    if (a < b)
                    {
                        break;
                    }
                    else if (a > b)
                    {
                        char ctem[1][25];
                        strcpy(ctem[0], N[j + 1]);
                        strcpy(N[j + 1], N[j]);
                        strcpy(N[j], ctem[0]);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << N[i] << " " << Sco[i] << endl;
    }
}