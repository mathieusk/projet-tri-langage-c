#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myFonction.h"

void InitTab(int* tab, int tailleTab, int nbrMax)
{
	for (int i=0; i<tailleTab ; i++)
		tab[i]= NbrRandom(nbrMax);
}

int NbrRandom(int max)
{
	static int first=0;

	if(first==0)
	{
		srand(time(NULL));
		first=1;
	}

	return (rand() / (double)RAND_MAX) * (max+1);
}

void TrierTab(int* tab, int tailleTab)
{
	int tmp;
	for(int i=0; i<tailleTab-1; i++)
		for(int j=i+1; j<tailleTab; j++)
			if (tab[i]>tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
}

void AfficherTab(int* tab, int tailleTab)
{
	for (int i=0; i<tailleTab ; i++)
	{
		printf("t[%d] = %d ",i, tab[i]);
		if(i<tailleTab-1) printf(", ");
	}
	printf("\n");
}
