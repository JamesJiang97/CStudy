#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int a, n, g = 1;
    cin >> a >> n;
    for(int i = 0; i < n; i++){
        g = g * a;
    }
    printf("%d", g);
}