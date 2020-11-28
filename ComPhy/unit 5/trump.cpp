#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int trp[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int n = 13;
    int ntry;
    cin >> ntry;
    double ncount = 0.0;
    for (int i = 1; i <= ntry; i++)
    {
        int flag = 1;
        int T = 10000;
        while (T)
        {
            int i = rand() % 13;
            int j = rand() % 13;
            int tmp = trp[i];
            trp[i] = trp[j];
            trp[j] = tmp;
            T--;
        }
        for (int j = 0; j < n; j++)
        {
            if (trp[j] == j+1)
            {
                flag = 0;
                break;
            }
        }
        if (flag){
            ncount += 1.0;
        }
        double s = ncount/i;
        cout << i << " " << s << endl;
    }
}