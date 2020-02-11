#include <stdio.h>
#include <stdlib.h>

#include "myFonction.h"

int main()
{
    int tmp, k=TAILLE_TAB-1, i, kPrime;
    int tab[TAILLE_TAB];

    InitTab(tab,TAILLE_TAB, NB_MAX);
    AfficherTab(tab,TAILLE_TAB);

	while(k>0)
    {
        tmp=-1;
		for(i=0; i<k; i++)
            if (tab[i]>tab[i+1])
			{
				tmp = tab[i+1];
				tab[i+1] = tab[i];
				tab[i] = tmp;
				kPrime=i;
			}
        if(tmp!=-1)
            k=kPrime;
        else
            k=0;

        AfficherTab(tab,TAILLE_TAB);
        printf("kPrime=%d ; k=%d\n",kPrime,k);
    }

    return 0;
}
