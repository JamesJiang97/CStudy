#include <iostream>
#include <cstdio>
#include <random>
#include <fstream>

using namespace std;

mt19937_64 g(time(0));

void game2(int *gamer, int n)
{
    while (1)
    {
        double dice1 = (g() / (mt19937_64::max() + 0.0)) * n;
        double dice2 = (g() / (mt19937_64::max() + 0.0)) * n;
        int d1 = (int)dice1, d2 = (int)dice2;
        if (gamer[d2] == 0)
        {
            return;
        }
        gamer[d1] += 1;
        gamer[d2] -= 1;
    }
}

int main()
{
    ofstream O1("dice1.dat");
    int n = 100;
    int m = n * 100;
    int dice1[m];
    for (int i = 0; i < m; i++)
    {
        dice1[i] = 0;
    }
    for (int i = 0; i < 100000; i++)
    {

        int gamer[n];
        for (int i = 0; i < n; i++)
        {
            gamer[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            double dice = (g() / (mt19937_64::max() + 0.0)) * n;
            int d = (int)dice;
            gamer[d]++;
        }
        game2(gamer, n);
        for (int i = 0; i < n; i++)
        {
            //O << i << " " << gamer[i] << endl;
            dice1[gamer[i]]++;
        }
    }
    //ofstream O("dice.dat");

    for (int i = 0; i < 500; i++)
    {

        O1 << i << " " << dice1[i] << endl;
    }
}
