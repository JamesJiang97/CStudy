#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, a, b, x = 0, z = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >>b;
        if(a<=140 && a>=90 && b<=90 && b>=60){
            x++;
            if(x>z){z = x;}
        }
        else
        {
            x = 0;
        }
        
    }
    cout << z;
}
