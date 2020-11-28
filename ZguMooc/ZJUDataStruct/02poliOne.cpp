#include <iostream>
#include <cstdio>

using namespace std;

typedef struct LNode *List;
struct LNode
{
    int coef;
    int expon;
    List next;
};

List PtrL1 = (List)malloc(sizeof(struct LNode));
List PtrL2 = (List)malloc(sizeof(struct LNode));

void crtList(List PtrL)
{
    int n;
    List p;
    p = PtrL;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c, e;
        cin >> c >> e;
        p->coef = c;
        p->expon = e;
        if (i != n - 1)
        {
            List s = (List)malloc(sizeof(struct LNode));
            p->next = s;
            p = s;
        }
    }
}

List multi(List PtrLa, List PtrLb)
{
    List PtrR = (List)malloc(sizeof(struct LNode));
    List p, temp;
    p = PtrR;
    temp = PtrLb;
    while (PtrLa != NULL)
    {
        while (PtrLb != NULL)
        {
            p->coef = PtrLa->coef * PtrLb->coef;
            p->expon = PtrLa->expon + PtrLb->expon;
            if (PtrLa->next != NULL || PtrLb->next != NULL)
            {
                List s = (List)malloc(sizeof(struct LNode));
                p->next = s;
                p = s;
            }
            PtrLb = PtrLb->next;
        }
        PtrLb = temp;
        PtrLa = PtrLa->next;
    }
    return PtrR;
}

List addit(List PtrLa, List PtrLb)
{
    List PtrR = (List)malloc(sizeof(struct LNode));
    List p;
    p = PtrR;
    while (PtrLa != NULL)
    {
        p->coef = PtrLa->coef;
        p->expon = PtrLa->expon;
        List s = (List)malloc(sizeof(struct LNode));
        p->next = s;
        p = s;
        PtrLa = PtrLa->next;
    }
    while (PtrLb != NULL)
    {
        p->coef = PtrLb->coef;
        p->expon = PtrLb->expon;
        if (PtrLb->next != NULL)
        {
            List s = (List)malloc(sizeof(struct LNode));
            p->next = s;
            p = s;
        }
        PtrLb = PtrLb->next;
    }
    return PtrR;
}

int getSize(List PtrL)
{
    List p = PtrL;
    int size = 0;
    while (p)
    {
        p = p->next;
        size++;
    }
    return size;
}

void sortList(List PtrL, int size)
{
    List p = PtrL;
    List temp = p;
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (p->expon < p->next->expon)
            {
                int temc = p->coef;
                int teme = p->expon;
                p->coef = p->next->coef;
                p->expon = p->next->expon;
                p->next->coef = temc;
                p->next->expon = teme;
            }
            p = p->next;
        }
        p = temp;
    }
}

void formatList(List PtrL)
{
    List p = PtrL;
    while (p && p->next)
    {
        while (p->expon == p->next->expon)
        {
            List temp = p->next;
            p->coef += temp->coef;
            p->next = temp->next;
            free(temp);
        }
        p = p->next;
    }
}

void showList(List PtrL)
{
    while (PtrL != NULL)
    {
        if (PtrL->next == NULL)
        {
            cout << PtrL->coef << " " << PtrL->expon << endl;
            return;
        }
        cout << PtrL->coef << " " << PtrL->expon << " ";
        PtrL = PtrL->next;
    }
}

int main()
{
    crtList(PtrL1);
    crtList(PtrL2);
    List multiL = multi(PtrL1, PtrL2);
    List additL = addit(PtrL1, PtrL2);
    int sizem = getSize(multiL);
    int sizea = getSize(additL);
    sortList(multiL, sizem);
    sortList(additL, sizea);
    formatList(multiL);
    formatList(additL);
    showList(multiL);
    showList(additL);
}