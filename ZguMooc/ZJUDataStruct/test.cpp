#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n = 8;
    int c = 0;
    for (int i = n-1; i ; i--){
        c += i;
    }
    cout << c;
}