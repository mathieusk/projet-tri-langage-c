#include <stdio.h>
#include <stdlib.h>

#include "myFonction.h"

int main()
{
    int tmp=-1, k1=TAILLE_TAB-1, i, kPrime=0, k2=0;
    int tab[TAILLE_TAB];

    InitTab(tab,TAILLE_TAB, NB_MAX);
    AfficherTab(tab,TAILLE_TAB);

	while(k1!=k2)
    {
		for(i=k2; i<k1; i++)
            if (tab[i]>tab[i+1])
			{
				tmp = tab[i+1];
				tab[i+1] = tab[i];
				tab[i] = tmp;
				kPrime=i;
			}
        if(tmp!=-1)
        {
            k1=kPrime;
            tmp=-1;
        }
        else
            k1=k2;

        printf("kPrime=%d ; k1=%d\n",kPrime,k1);

        for(i=k1; i>k2; i--)
            if(tab[i]<tab[i-1])
            {
                tmp=tab[i-1];
                tab[i-1]=tab[i];
                tab[i]=tmp;
                kPrime=i;
            }
        if(tmp!=-1)
        {
            k2=kPrime;
            tmp=-1;
        }
        else
            k1=k2;

        printf("kPrime=%d ; k2=%d\n",kPrime,k2);
        AfficherTab(tab,TAILLE_TAB);

    }

    return 0;
}
