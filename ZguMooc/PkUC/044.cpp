#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char O[81], A[81] = "", o[2];
    gets(O);
    for (int i = 0; O[i]; i++)
    {
        if ((O[i] >= 'a' && O[i] < 'z') || (O[i] >= 'A' && O[i] < 'Z'))
        {
            A[i] = O[i] + 1;
        }
        else if (O[i] == 'z' || O[i] == 'Z')
        {
            A[i] = O[i] - 25;
        }
        else{
            A[i] = O[i];
        }
    }
    cout << A << endl;
}