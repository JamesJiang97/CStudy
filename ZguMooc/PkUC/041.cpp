#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char A[100001];
    cin >> A;
    int len = strlen(A);
    for (int i = 0; i < len; i++)
    {
        int flag = 1;
        if (!A[i])
        {
            continue;
        }
        for (int j = i + 1; j < len; j++)
        {
            if (A[i] == A[j])
            {
                flag = 0;
                A[j] = 0;
            }
        }
        if (flag)
        {
            cout << A[i];
            return 0;
        }
    }
    cout << "no";
}