#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    unsigned long n;
    cin >> n;
    if (n == 1)
    {
        printf("End");
        return 0;
    }

    while (n != 1)
    {
        if (n % 2)
        {
            printf("%ld*3+1=%ld\n", n, n * 3 + 1);
            n = n * 3 + 1;
            continue;
        }
        else if (n % 2 == 0)
        {
            printf("%ld/2=%ld\n", n, n / 2);
            n = n / 2;
            if (n == 1)
            {
                printf("End");
                return 0;
            }
        }
    }
}