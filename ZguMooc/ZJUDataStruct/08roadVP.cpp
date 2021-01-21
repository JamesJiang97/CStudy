#include <iostream>
#include <cstdio>

using namespace std;

struct Road
{
    int c1;
    int c2;
    int cost;
} R[3050];

struct City
{
    int c;
    int parent;
} C[1005];

int N, M, V = 0, Tcost = 0, tag = 1;

void Quicksort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        double x = R[mid].cost;
        int i = low, j = high;
        while (i <= j)
        {
            while (R[i].cost < x)
            {
                i++;
            }
            while (R[j].cost > x)
            {
                j--;
            }
            if (i <= j)
            {
                struct Road Tmp = R[j];
                R[j] = R[i];
                R[i] = Tmp;
                i++;
                j--;
            }
        }
        Quicksort(low, j);
        Quicksort(i, high);
    }
}

void Init()
{

    for (int i = 0; i < M; i++)
    {
        cin >> R[i].c1 >> R[i].c2 >> R[i].cost;
    }
    for (int i = 1; i <= N; i++)
    {
        C[i].c = 0;
        C[i].parent = 0;
    }
    Quicksort(0, M - 1);
}

void PushR(Road R)
{
    int c1 = R.c1, c2 = R.c2;
    if (C[c1].c > 0 && C[c2].c > 0 && C[c1].parent == C[c2].parent)
    {
        return;
    }
    if (C[c1].c > 0 && C[c2].c > 0 && C[c1].parent != C[c2].parent)
    {
        for (int i = 1; i <= N; i++)
        {
            if (C[i].parent == C[c2].parent)
            {
                C[i].parent = C[c1].parent;
            }
        }
        V++;
        Tcost += R.cost;
    }
    else if (C[c1].c > 0 && C[c2].c == 0 && C[c1].parent != C[c2].parent)
    {
        C[c2].c = c2;
        C[c2].parent = C[c1].parent;
        V++;
        Tcost += R.cost;
    }
    else if (C[c1].c == 0 && C[c2].c > 0 && C[c1].parent != C[c2].parent)
    {
        C[c1].c = c1;
        C[c1].parent = C[c2].parent;
        V++;
        Tcost += R.cost;
    }
    else if (C[c1].c == 0 && C[c2].c == 0)
    {

        C[c1].c = c1;
        C[c2].c = c2;
        C[c1].parent = tag++;
        C[c2].parent = C[c1].parent;
        V++;
        Tcost += R.cost;
    }
}

void Kruskal()
{
    for (int i = 0; i < M; i++)
    {
        if(V == N){
            break;
        }
        PushR(R[i]);
    }
}

int main()
{
    cin >> N >> M;
    Init();
    Kruskal();
    if (V != N - 1)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << Tcost << endl;
    }
}