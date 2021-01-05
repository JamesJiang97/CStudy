#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>

#define eps 1e-20

using namespace std;

typedef struct CNode *Croc;
struct CNode
{
    int x;
    int y;
    int dist;
    int path;
    bool isSafe;
    double d;
} C[105];

int N, D;
CNode Cmin;
CNode C0;

double Distance(CNode C1, CNode C2)
{
    double x2 = pow(C1.x - C2.x, 2), y2 = pow(C1.y - C2.y, 2);
    double distance = sqrt(x2 + y2);
    return distance;
}

void Init()
{
    C0.x = 0, C0.y = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i].x >> C[i].y;
        if (abs(C[i].x - 50) <= D || abs(C[i].x + 50) <= D || abs(C[i].y + 50) <= D || abs(C[i].y - 50) <= D)
        {
            C[i].isSafe = 1;
        }
        else
        {
            C[i].isSafe = 0;
        }
        C[i].dist = 10000;
    }
}

void Scan(int v)
{
    int e;
    queue<int> q;
    q.push(v);
    C[v].dist = 1;
    while (!q.empty())
    {
        e = q.front();
        q.pop();
        if (C[e].isSafe == 1 && C[e].dist < Cmin.dist)
        {
            Cmin = C[e];
            return;
        }
        for (int i = 0; i < N; i++)
        {
            if (C[i].dist > C[e].dist + 1 && Distance(C[e], C[i]) <= D)
            {
                q.push(i);
                C[i].path = e;
                C[i].dist = C[e].dist + 1;
            }
        }
    }
}

void Opath(CNode E)
{
    if (E.dist == 100000)
    {
        cout << "0" << endl;
        return;
    }
    stack<int> q;
    cout << E.dist + 1 << endl;
    while (1)
    {
        q.push(E.y);
        q.push(E.x);
        if (E.dist == 1)
        {
            break;
        }
        E = C[E.path];
    }
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
        cout << q.top() << endl;
        q.pop();
    }
}

double Dt0(CNode C)
{
    double x2 = pow(C.x, 2), y2 = pow(C.y, 2);
    double distance = sqrt(x2 + y2);
    return distance;
}

void Quicksort(int low, int high)
{
    for(int i = 0; i < N; i++){
        C[i].d = Dt0(C[i]);
    }
    if (low < high)
    {
        int mid = (low + high) / 2;
        double x = C[mid].d;
        int i = low, j = high;
        while (i <= j)
        {
            while (C[i].d + eps < x)
            {
                i++;
            }
            while (C[j].d > x + eps)
            {
                j--;
            }
            if (i <= j)
            {
                struct CNode Tmp = C[j];
                C[j] = C[i];
                C[i] = Tmp;
                i++;
                j--;
            }
        }
        Quicksort(low, j);
        Quicksort(i, high);
    }
}

int main()
{

    Cmin.dist = 100000;
    cin >> N >> D;
    if (D >= 42.5)
    {
        cout << "1" << endl;
        return 0;
    }
    Init();
    Quicksort(0, N - 1);
    for (int i = 0; i < N; i++)
    {
        double x2 = pow(C[i].x, 2), y2 = pow(C[i].y, 2);
        if (sqrt(x2 + y2) <= D + 7.5)
        {
            Scan(i);
        }
    }
    Opath(Cmin);
}