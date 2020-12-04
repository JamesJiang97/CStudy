#include <iostream>
#include <cstdio>

using namespace std;

typedef struct HNode *Heap;
struct HNode{
    int *Data;
    int Size;
    int Capacity;
};

#define MINDATA -10001 
#define MAXSIZE 1001

Heap creatHeap(){
    Heap H = (Heap)malloc(sizeof(HNode));
    H->Data = (int *)malloc(MAXSIZE*sizeof(int));
    H->Size = 0;
    H->Capacity = MAXSIZE;
    H->Data[0] = MINDATA;
    return H;
}

void add(int data, Heap H){
    H->Data[++H->Size] = data;
    int i = H->Size;
    while (H->Data[i] < H->Data[i/2])
    {
        int tmp = H->Data[i];
        H->Data[i] = H->Data[i/2];
        H->Data[i/2] = tmp;
        i /= 2;
    }
}


int main(){
    int N, M;
    cin >> N >> M;
    Heap H = creatHeap();
    for (int i = 0; i < N; i++)
    {
        int d;
        cin >> d;
        add(d, H);
    }
    for(int i = 0; i < M; i++){
        int m;
        cin >> m;
        while(m > 1){
            cout << H->Data[m] << " ";
            m /= 2;
        }
        cout << H->Data[m] << endl;
    }    
}