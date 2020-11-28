#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

typedef struct LinkedL *List;
struct LinkedL
{
    int Adress;
    int Data;
    int NxtAdrs;
    List Next;
};

int N, K;

#define MAXSIZE 100000

List createList()
{
    int HAdrs;
    cin >> HAdrs >> N >> K;
    LinkedL L[MAXSIZE];
    List PtrL = (List)malloc(sizeof(struct LinkedL));
    for (int i = 0; i < N; i++)
    {
        int TAdrs, NxtAdrs, d;
        cin >> TAdrs >> d >> NxtAdrs;
        if (TAdrs >= MAXSIZE || TAdrs < 0)
        {
            continue;
        }
        L[TAdrs].Adress = TAdrs;
        L[TAdrs].Data = d;
        L[TAdrs].NxtAdrs = NxtAdrs;
        if (NxtAdrs != -1)
        {
            L[TAdrs].Next = &L[NxtAdrs];
        }
    }
    PtrL->Adress = L[HAdrs].Adress, PtrL->Data = L[HAdrs].Data, PtrL->NxtAdrs = L[HAdrs].NxtAdrs;
    List tmp = PtrL;
    List ls = L[HAdrs].Next;
    for (int i = 1; i < N; i++)
    {
        List s = (List)malloc(sizeof(struct LinkedL));
        s->Adress = ls->Adress, s->Data = ls->Data, s->NxtAdrs = ls->NxtAdrs;
        tmp->Next = s;
        tmp = tmp->Next;
        ls = ls->Next;
    }
    return PtrL;
}

void reverseL(List PtrL)
{
    int i = 1, j = K;
    while (j - i > 0)
    {
        List Li = PtrL;
        List Lj = PtrL;
        for (int a = 1; a < i; a++)
        {
            Li = Li->Next;
        }
        for (int a = 1; a < j; a++)
        {
            Lj = Lj->Next;
        }
        int tmpA = Li->Adress, tmpD = Li->Data, tmpN = Li->NxtAdrs;
        Li->Adress = Lj->Adress;
        Li->Data = Lj->Data;
        Li->NxtAdrs = Lj->NxtAdrs;
        Lj->Adress = tmpA;
        Lj->Data = tmpD;
        Lj->NxtAdrs = tmpN;
        i++;
        j--;
    }
    List tmp = PtrL;
    while (tmp)
    {
        if (tmp->Next)
        {
            tmp->NxtAdrs = tmp->Next->Adress;
        }
        else
        {
            tmp->NxtAdrs = -1;
        }
        tmp = tmp->Next;
    }
}

void showList(List PtrL)
{
    List tmp = PtrL;
    while (tmp)
    {
        cout.fill('0');
        if (tmp->NxtAdrs == -1)
        {
            cout << setw(5) << tmp->Adress << " " << tmp->Data << " " << tmp->NxtAdrs << endl;
            tmp = tmp->Next;
        }
        else
        {
            cout << setw(5) << tmp->Adress << " " << tmp->Data << " " << setw(5) << tmp->NxtAdrs << endl;
            tmp = tmp->Next;
        }
    }
}

int main()
{
    List L = createList();
    reverseL(L);
    showList(L);
}