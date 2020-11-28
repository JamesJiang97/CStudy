#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n;
    double t, av, x, y;
    cin >> n;
    cin >> t >> av;
    x = (av/t) * 100;
    for(int i = 0; i < n-1; i++){
        cin >> t >> av;
        y = (av/t) * 100;
        double a = y - x;
        if (a > 5)
        {
            cout << "better" << endl;
        }
        else if (a < -5)
        {
            cout << "worse" << endl;
        }
        else
        {
            cout << "same" << endl;
        }
    }
}