#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int m, n, pl;
    cin >> n >> m;
    m *= 1.5;
    int p[n], sco[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> sco[i];
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (sco[j] < sco[j + 1])
            {
                int tem = sco[j + 1];
                sco[j + 1] = sco[j];
                sco[j] = tem;
                int ptem = p[j + 1];
                p[j + 1] = p[j];
                p[j] = ptem;
            }
            else if (sco[j] == sco[j + 1])
            {
                if (p[j] > p[j + 1])
                {
                    int tem = sco[j + 1];
                    sco[j + 1] = sco[j];
                    sco[j] = tem;
                    int ptem = p[j + 1];
                    p[j + 1] = p[j];
                    p[j] = ptem;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (i == m-1)
        {
            pl = sco[i];
        }
        if (i > m-1)
        {
            if (sco[i] == sco[i - 1])
            {
                m++;
            }else
            {
                break;
            }
            
        }
    }
    cout << pl << " " << m << endl;
    for (int i = 0; i < m; i++)
    {
        cout << p[i] << " " << sco[i] << endl;
    }
}