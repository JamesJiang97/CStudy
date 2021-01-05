#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct CNode *Croc;
struct CNode
{
    int x;
    int y;
    bool visited;
} C[105];

int N, D, isSafe = 0;

void DFS(CNode E)
{
    double x = E.x, y = E.y;
    if (abs(x - 50) <= D || abs(x + 50) <= D || abs(y + 50) <= D || abs(y - 50) <= D)
    {
        isSafe = 1;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (C[i].visited)
        {
            continue;
        }
        double x2 = pow(x - C[i].x, 2), y2 = pow(y - C[i].y, 2);
        if (sqrt(x2 + y2) <= D)
        {
            C[i].visited = 1;
            DFS(C[i]);
        }
    }
    return;
}

int main()
{
    cin >> N >> D;
    CNode e;
    e.x = 0;
    e.y = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i].x >> C[i].y;
        C[i].visited = 0;
    }
    for (int i = 0; i < N; i++)
    {
        if (C[i].visited)
        {
            continue;
        }
        double x2 = pow(C[i].x, 2), y2 = pow(C[i].y, 2);
        if (sqrt(x2 + y2) <= D + 7.5)
        {
            C[i].visited = 1;
            DFS(C[i]);
        }
        if (isSafe)
        {
            break;
        }
    }
    if (isSafe)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}