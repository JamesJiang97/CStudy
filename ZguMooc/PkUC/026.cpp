#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int M, N , X, m = 0;
    cin >> M >> N >> X;
    while(X){
        if(m < M && X > 0){
            m += N;
            if (m > M)
            {
                m = M;
            }
            X--;
        }
        int d = 0;
        if(m == M){
            int n = N;
            for(int i = 0; i < M; i++){
                d++;
                if(d == n){
                    N++;
                    d = 0;
                }
            }
            m = 0;
        }
    }
    cout << N;
}