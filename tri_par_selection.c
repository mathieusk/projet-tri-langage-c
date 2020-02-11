#include <stdio.h>
#include <stdlib.h>

#include "myFonction.h"

int main()
{
    int j=0, tmp=0;
    int t[TAILLE_TAB];

    InitTab(t, TAILLE_TAB, NB_MAX);
    AfficherTab(t, TAILLE_TAB);

    for(int k=TAILLE_TAB-1; k>0; k--)
    {
        j=0;
        for(int i=0; i<=k; i++)
            if(t[j]<t[i])
                j=i;
        tmp=t[k];
        t[k]=t[j];
        t[j]=tmp;
    }

    AfficherTab(t, TAILLE_TAB);

    return 0;
}
