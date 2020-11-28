#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long n, x = 0;
    cin >> n;
    while(n){
        x = x * 10 + n % 10;
        n /= 10;
    }
    cout << x;
}