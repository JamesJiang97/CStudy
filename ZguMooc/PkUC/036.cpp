#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    unsigned int a, b, c;
    cin >> a >> b;
    if(a < b){
        a = a ^ b;
        b = b ^ a;
        a = a ^ b;
    }
    while(a%b){
        c = b;
        b = a%b;
        a = c;
    }
    cout << b;
}