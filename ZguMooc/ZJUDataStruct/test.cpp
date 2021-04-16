#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int x = 8;
    int *ptr = &x;
    int y = *&x;
    cout << y << endl;
    printf("%d", y);
}