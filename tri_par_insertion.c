#include <stdio.h>
#include <stdlib.h>
#include "myFonction.h"


int main()
{
    int tab[TAILLE_TAB];
    int k;
    int j;
    int tmp;

    InitTab(tab,TAILLE_TAB,NB_MAX);
    AfficherTab(tab,TAILLE_TAB);
    printf("\n");

    for(k=1; k<TAILLE_TAB; k++)
    {
        j=k;
        tmp=tab[k];
        while (j-1>=0 && tmp<tab[j-1])
        {
            tab[j]=tab[j-1];
            j--;
        }
        tab[j]=tmp;
    }
    AfficherTab(tab,TAILLE_TAB);
	
	// améliorer ce tri en faisant une recherche par dichotomie sur la partie trié du tableau 

    return 0;
}
