#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n, x, sum = 0;
    double adv = 0.0;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> x;
        sum = sum + x;
        adv = sum /(i+1.0);
    }
    printf("%d %.5lf", sum, adv);
}