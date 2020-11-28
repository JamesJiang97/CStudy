#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int a, b, n;
    char q;
    cin >> a >> b >> q;
    int f = (int)q;
    if (f == 42)
    {
        n = a * b;
        cout << n;
    }
    else if (f == 43)
    {
        n = a + b;
        cout << n;
    }
    else if (f == 45)
    {
        n = a - b;
        cout << n;
    }
    else if (f == 47)
    {
        if (b == 0)
        {
            cout << "Divided by zero!";
        }
        else
        {
            n = a / b;
            cout << n;
        }
        
    }
    else
    {
        cout << "Invalid operator!";
    }
}