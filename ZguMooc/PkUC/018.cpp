#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    int Maxx=0, Minx=1000;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > Maxx){Maxx = x;}
        if(x < Minx){Minx = x;}
    }
    int s = Maxx - Minx;
    cout << s;
}