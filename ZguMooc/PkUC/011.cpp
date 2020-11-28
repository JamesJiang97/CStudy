#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int h, r;
    scanf("%d%d", &h, &r);
    double v = 3.14159 * r * r * h * 0.001;
    double n = 20 / v;
    int a = (int)n;
    a++;
    printf("%d", a);
}