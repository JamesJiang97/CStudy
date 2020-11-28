#include <iostream>
#include <cmath>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    double n = b*b - 4*a*c;
    if (b*b == 4*a*c)
    {
        printf("x1=x2=%.5lf", (0-b + sqrt(n))/(2*a));
    }
    else if (b*b > 4*a*c)
    {
        double x1 = (0-b + sqrt(n))/(2*a);
        double x2 = (0-b - sqrt(n))/(2*a);
        printf("x1=%.5lf;x2=%.5lf", x1, x2);
    }
    else
    {
        double re = (0-b)/(2*a);
        double lm = sqrt(4*a*c - b*b)/(2*a);
        printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi",re, lm, re, lm);
    }
}