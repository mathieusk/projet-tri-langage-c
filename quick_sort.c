#include <stdio.h>
#include <stdlib.h>

#include "myFonction.h"

void quick_sort(int debut, int fin, int t[])
{
    int p ,i ,tmp, j;
    j=debut;
    p=t[fin];
    i=j-1;

    while(j<fin)
    {
        if(t[j]<=p)
        {
            i++;
            if(i!=j)
            {
                tmp=t[i];
                t[i]=t[j];
                t[j]=tmp;
            }
        }
        j++;
    }

    i++;
    tmp=t[i];
    t[i]=p;
    t[fin]=tmp;


    for(int k=debut; k<=fin; k++)
            printf(" t[%d]=%d", k, t[k]);
    printf(" pivot = %d \n",p);

    if(i-debut-1 >= 1)
    {
        printf("appel 1 ");
        quick_sort(debut, i-1, t);
    }
    if(fin-(i+1) >= 1)
    {
        printf("appel 2 ");
        quick_sort(i+1, fin, t);
    }
}

int main()
{
    int tab[TAILLE_TAB];

    InitTab(tab,TAILLE_TAB, NB_MAX);
    AfficherTab(tab,TAILLE_TAB);

    quick_sort(0, TAILLE_TAB-1, tab);

    AfficherTab(tab, TAILLE_TAB);

    return 0;
}
