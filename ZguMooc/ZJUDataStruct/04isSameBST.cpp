#include <iostream>
#include <cstdio>

using namespace std;

typedef struct BSTNode *BST;
struct BSTNode
{
    int Data;
    BST Lift;
    BST Right;
};

void addBSTNode(int d, BST Top);

BST createBST(int n)
{
    BST T = (BST)malloc(sizeof(struct BSTNode));
    int d;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        addBSTNode(d, T);
    }
    return T;
}

void addBSTNode(int d, BST Top)
{
    if (Top->Data == 0)
    {
        Top->Data = d;
        return;
    }
    else
    {
        if (d > Top->Data)
        {
            if (!Top->Right)
            {
                BST T = (BST)malloc(sizeof(struct BSTNode));
                Top->Right = T;
            }
            addBSTNode(d, Top->Right);
        }
        else
        {
            if (!Top->Lift)
            {
                BST T = (BST)malloc(sizeof(struct BSTNode));
                Top->Lift = T;
            }
            addBSTNode(d, Top->Lift);
        }
    }
}

int isSameBST(BST T, BST cT)
{
    if (!T && !cT)
    {
        return 1;
    }
    if (T && !cT || !T && cT)
    {
        return 0;
    }
    if (T->Data != cT->Data)
    {
        return 0;
    }
    else
    {
        return (isSameBST(T->Lift, cT->Lift) && isSameBST(T->Right, cT->Right));
    }
}

int main()
{
    while (1)
    {
        int N, L;
        cin >> N >> L;
        if (N == 0)
        {
            break;
        }
        BST T = createBST(N);
        while (L--)
        {
            BST cT = createBST(N);
            if (isSameBST(T, cT))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}