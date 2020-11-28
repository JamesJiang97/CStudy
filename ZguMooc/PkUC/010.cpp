#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    double r;
    double v;
    scanf("%lf", &r);
    v = 4/3.0*3.14*r*r*r;
    printf("%.2f", v);
}