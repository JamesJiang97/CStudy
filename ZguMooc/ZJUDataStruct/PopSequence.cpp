#include <iostream>
#include <cstdio>

using namespace std;

#define MAXSIZE 1005

int isFull = 0;

typedef struct SNode *Stack;
struct SNode
{
    int Data[MAXSIZE];
    int Top;
};

void Push(Stack PtrS, int n)
{

    PtrS->Data[++(PtrS->Top)] = n;
}

void Pop(Stack PtrS)
{

    PtrS->Data[(PtrS->Top)--];
}

int main()
{
    int M, N, K;
    cin >> M >> N >> K;
    for (int c = 0; c < K; c++)
    {
        Stack S = (Stack)malloc(sizeof(struct SNode));
        S->Top = -1;
        int mark = 1;
        int flag = 1;
        int arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        for (int d = 0; d < N; d++)
        {
            while ( S->Top == -1|| S->Data[S->Top] != arr[d])
            {
                if (mark > N)
                {
                    break;
                }
                Push(S, mark);
                mark++;
            }
            if (S->Data[S->Top] != arr[d] || S->Top == -1)
            {
                flag = 0;
                break;
            }
            else
            {
                Pop(S);
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        free(S);
    }
}
