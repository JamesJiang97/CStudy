#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char A[100000], Word[201] = "", MaxW[201], MinW[201], Emp[] = "", W[2];
    int n = 0, Max = -1, Min = 200;
    gets(A);
    int len = strlen(A);
    for (int i = 0; i < len + 1; i++)
    {
        if (A[i] != ' ' && A[i] != ',' && A[i] != '\0')
        {
            n++;
            W[0] = A[i];
            strcat(Word, W);
        }
        else
        {
            if (strlen(Word) == 0)
            {
                continue;
            }
            if (n > Max)
            {
                Max = n;
                strcpy(MaxW, Word);
            }
            if (n < Min)
            {
                Min = n;
                strcpy(MinW, Word);
            }
            strcpy(Word, Emp);
            n = 0;
        }
    }
    cout << MaxW << endl;
    cout << MinW << endl;
}