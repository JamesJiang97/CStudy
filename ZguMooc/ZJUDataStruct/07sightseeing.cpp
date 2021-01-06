#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct HighWay
{
    int c1;
    int c2;
    int dist;
    int cost;
} H[100000];

struct City
{
    int path;
    int dist;
    int cost;
} C[510];

int N, M;

void Init()
{
    for (int i = 0; i < M; i++)
    {
        cin >> H[i].c1 >> H[i].c2 >> H[i].dist >> H[i].cost;
    }
    for (int i = 0; i < N; i++)
    {
        C[i].dist = 260000;
        C[i].cost = 260000;
    }
}

void Dijkstra(int ori)
{
    queue<int> q;
    q.push(ori);
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = 0; i < M; i++)
        {
            if (H[i].c1 == p &&
                (C[H[i].c2].dist > C[p].dist + H[i].dist ||
                 (C[H[i].c2].dist == C[p].dist + H[i].dist && C[H[i].c2].cost > C[p].cost + H[i].cost)))
            {
                int n = H[i].c2;
                q.push(n);
                C[n].dist = C[p].dist + H[i].dist;
                C[n].cost = C[p].cost + H[i].cost;
                C[n].path = p;
            }
            if (H[i].c2 == p &&
                (C[H[i].c1].dist > C[p].dist + H[i].dist ||
                 (C[H[i].c1].dist == C[p].dist + H[i].dist && C[H[i].c1].cost > C[p].cost + H[i].cost)))
            {
                int n = H[i].c1;
                q.push(n);
                C[n].dist = C[p].dist + H[i].dist;
                C[n].cost = C[p].cost + H[i].cost;
                C[n].path = p;
            }
        }
    }
}

int main(){
    int ori, des;
    cin >> N >> M >> ori >> des;
    Init();
    C[ori].cost = 0;
    C[ori].dist = 0; 
    Dijkstra(ori);
    cout << C[des].dist << " " << C[des].cost << endl;
}
