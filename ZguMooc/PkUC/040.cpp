#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int x = 0;
    char A[256];
    gets(A);
    int len = strlen(A);
    for(int i = 0; i < len; i++)
    {
        int n = (int)A[i];
        if(n>= 48 && n<=57){
            x++;
        }
    }
    cout << x;
}