#include <iostream>
#include <cstdio>

using namespace std;

typedef struct TNode *Tree;
struct TNode
{
    int Data;
    Tree Lift;
    Tree Right;
} T[11];

Tree createTree(int n)
{

    int c = 0;
    for (int i = n - 1; i; i--)
    {
        c += i;
    }
    for (int i = 0; i < n; i++)
    {
        char l, r;
        cin >> l >> r;
        int L = l -'0', R = r -'0';
        T[i].Data = i;
        if (L >= 0 && L <= 9)
        {
            T[i].Lift = &T[L];
            c -= L;
        }
        if (R >= 0 && R <= 9)
        {
            T[i].Right = &T[R];
            c -= R;
        }
    }
    return &T[c];
}

int main()
{
    int n;
    cin >> n;
    Tree T1 = createTree(n);
    Tree LT[11] ;
    LT[0] = T1;
    for (int i = 0, c = 0; i < n; i++)
    {
        if (LT[i]->Lift)
        {
            LT[++c] = LT[i]->Lift;
        }
        if (LT[i]->Right)
        {
            LT[++c] = LT[i]->Right;
        }
    }
    for (int i = 0; i < n; i++){
        if(!LT[i]->Lift&&!LT[i]->Right&&i != n-1){
            cout << LT[i]->Data << " ";
        }else if(!LT[i]->Lift&&!LT[i]->Right&&i == n-1)
        {
            cout << LT[i]->Data;
        }
        
    }
}