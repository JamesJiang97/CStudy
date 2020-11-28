#include <iostream>
#include <cstdio>

using namespace std;

typedef struct BSTNode *BST;
struct BSTNode
{
    int Data;
    BST Lift = NULL;
    BST Right = NULL;
};

BST createBST(int n)
{
    BST T = (BST)malloc(sizeof(struct BSTNode));
    BST tmp = T;
    int d;
    cin >> d;
    for (int i = 0; i < n; i++)
    {

        tmp->Data = d;
        cin >> d;
        if (d > tmp->Data)
        {
            BST tmp1 = (BST)malloc(sizeof(struct BSTNode));
            tmp->Right = tmp1;
            tmp = tmp->Right;
        }
        else
        {
            BST tmp1 = (BST)malloc(sizeof(struct BSTNode));
            tmp->Lift = tmp1;
            tmp = tmp->Lift;
        }
    }
    return T;
}
