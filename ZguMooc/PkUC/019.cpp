#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n, g, s, b, G = 0, S = 0, B = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> g >> s >> b;
        G = G + g;
        S = S + s;
        B = B + b;
    }
    int T = G + S + B;
    printf("%d %d %d %d", G, S, B, T);
}