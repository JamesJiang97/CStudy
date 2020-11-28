#include <iostream>
#include <cstdio>

using namespace std;

typedef struct TNode *Tree;
struct TNode
{
    char Data;
    Tree Left;
    Tree Right;
} T0[11], T1[11];

Tree createTree(TNode T[])
{
    int n;
    cin >> n;
    if (!n)
    {
        return 0;
    }
    int c = 0;
    for (int i = n - 1; i; i--)
    {
        c += i;
    }
    for (int i = 0; i < n; i++)
    {
        char D, l, r;
        cin >> D >> l >> r;
        T[i].Data = D;
        int L = l - '0', R = r - '0';
        if (L <= 9 && L >= 0)
        {
            T[i].Left = &T[L];
            c -= L;
        }
        if (R <= 9 && R >= 0)
        {
            T[i].Right = &T[R];
            c -= R;
        }
    }
    return &T[c];
}

int isIsomorphism(Tree PtrT1, Tree PtrT2)
{
    if (PtrT1 == NULL && PtrT2 == NULL)
    {
        return 1;
    }
    if (PtrT1 && PtrT2 == NULL || PtrT1 == NULL && PtrT2)
    {
        return 0;
    }
    if (PtrT1->Data != PtrT2->Data)
    {
        return 0;
    }
    if (!PtrT1->Left && !PtrT2->Left)
    {
        return isIsomorphism(PtrT1->Right, PtrT2->Right);
    }
    if (PtrT1->Left && PtrT2->Left && PtrT1->Left->Data == PtrT2->Left->Data)
    {
        return (isIsomorphism(PtrT1->Left, PtrT2->Left) && isIsomorphism(PtrT1->Right, PtrT2->Right));
    }
    else
    {
        return (isIsomorphism(PtrT1->Left, PtrT2->Right) && isIsomorphism(PtrT1->Right, PtrT2->Left));
    }
}

int getHeight(Tree PtrT)
{
    int h = 0, hl = 0, hr = 0;
    if (PtrT)
    {
        hl = getHeight(PtrT->Left);
        hr = getHeight(PtrT->Right);
        h = (hl > hr) ? hl : hr;
        return (h + 1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    Tree Tr1 = createTree(T0);
    Tree Tr2 = createTree(T1);
    if (isIsomorphism(Tr1, Tr2))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}