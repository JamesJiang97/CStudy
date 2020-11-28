#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int N;
    cin >> N;
    char Player1[9], Player2[9];
    for (int i = 0; i < N; i++)
    {
        cin >> Player1 >> Player2;
        if (strlen(Player1) == strlen(Player2))
        {
            cout << "Tie" << endl;
            continue;
        }
        int n = strlen(Player1) - strlen(Player2);
        if (n == -4 || n == 3 || n == 1)
        {
            cout << "Player1" << endl;
            continue;
        }
        else
        {
            cout << "Player2" << endl;
        }
    }
}
