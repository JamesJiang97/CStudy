#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int L, R, n, z = 0;
    cin >> L >> R;
    for(int i = L; i <= R; i++){
        int a = i;
        while(a){
            n = a%10;
            if(n == 2){
                z++;
            }
            a /= 10;
        }
    }
    cout << z;
}