#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myFonction.h"

void InitTab(int tab[], int tailleTab, int nbrMax)
{
    for (int i=0; i<tailleTab ; i++)
		tab[i]= NbrRandom(nbrMax);
}

void CopyTab(int ori[], int tmp[], int tailleTab)
{
    for(int i=0; i<tailleTab; i++)
        tmp[i]=ori[i];
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

void AfficherTab(int* tab, int tailleTab)
{
	for (int i=0; i<tailleTab ; i++)
	{
		printf("t[%d] = %d ",i, tab[i]);
		if(i<tailleTab-1) printf(", ");
	}
	printf("\n");
}

int IsSorted(int tab[], int taille)
{
    for (int i=0; i<taille-1; i++)
        if(tab[i]>tab[i+1])
        {
            printf("tab[i]=%d ; tab[i+1]=%d",tab[i],tab[i+1]);
            return 0;
        }
    return 1;
}


float TriParInsertion(int tab[] ,int taille)
{
    clock_t t1, t2 ;
    int k;
    int j;
    int tmp;

    t1 = clock() ;

    for(k=1; k<taille; k++)
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
    t2 = clock();
    return (float)(t2-t1)/CLOCKS_PER_SEC;
}

float TriParSelection(int t[] ,int taille)
{
    int j=0, tmp=0;
    clock_t t1,t2;

    t1 = clock() ;

    for(int k=taille-1; k>0; k--)
    {
        j=0;
        for(int i=0; i<=k; i++)
            if(t[j]<t[i])
                j=i;
        tmp=t[k];
        t[k]=t[j];
        t[j]=tmp;
    }
    t2 = clock();
    return (float)(t2-t1)/CLOCKS_PER_SEC;
}

float TriParEchange(int tab[] ,int taille)
{
    int tmp, k=taille-1, i, kPrime;
    clock_t t1,t2;

    t1 = clock() ;

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
    }
    t2 = clock();
    return (float)(t2-t1)/CLOCKS_PER_SEC;
}

float ShakeSort(int tab[] ,int taille)
{
    int tmp=-1, k1=taille-1, i, kPrime=0, k2=0;
    clock_t t1,t2;

    t1 = clock() ;

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
    }
    t2 = clock();
    return (float)(t2-t1)/CLOCKS_PER_SEC;
}

void Placer(int g, int d, int *t)
{
    int j, x, place_trouvee;
    x=t[g];
    j=2*g+1;
    place_trouvee=0;

    while((j<=d) && !(place_trouvee))
    {
        if(j<d)
            if(t[j+1]>t[j]) j++;

        if(x>=t[j])
            place_trouvee=1;
        else
        {
            t[g]=t[j];
            g=j,
            j=2*g+1;
        }
    }
    t[g]=x;
}

float HeapSort(int tab[] ,int taille)
{
    int g, d, tmp;
    clock_t t1,t2;

    t1 = clock() ;

    d=taille-1;
    g=(d+1)/2;

    while(g>0)
    {
        g--;
        Placer(g,d,tab);
    }
    while(d>1)
    {
        tmp=tab[0];
        tab[0]=tab[d];
        tab[d]=tmp;
        d--;
        // quand il ne reste que 2 elements dans le tableau pas besoin d appeler la methode placer.
        if(d>1)
            Placer(g,d,tab);
    }
    if(tab[0]>tab[1])
    {
        tmp=tab[0];
        tab[0]=tab[1];
        tab[1]=tmp;
    }
    t2 = clock();
    return (float)(t2-t1)/CLOCKS_PER_SEC;
}

float ShellSort(int tab[] ,int taille)
{
    int tmp=0, j=0, i=0;
    int pas;
    clock_t t1,t2;

    t1 = clock() ;
    //recherche du pas max.
    pas=1;
    while ( 3*pas+1 < taille )
        pas = 3*pas+1;

    while(pas>=1)
    {
        // boucle pour faire le décalage de 1 sur le pas et donc créer les différents tableaux possible pour chaque pas.
        for(j=0; j<pas; j++)
        {
            // si le pas plus le décalage sup au tab on sort de la boucle, plus de tableau possible avec ce pas.
            if(pas+j >= taille)
                break;
            // tri par insertion simple mais réaliser avec le pas plus le déclage
            for(int k = pas+j ; k < taille; k+=pas)
            {
                i=k;
                tmp=tab[k];
                while( i-pas>=0 && tmp<tab[i-pas] )
                {
                    tab[i]=tab[i-pas];
                    i-=pas;
                }
                tab[i]=tmp;
            }
        }
        pas = (pas-1)/3;
    }
    t2 = clock();

    return (float)(t2-t1)/CLOCKS_PER_SEC;
}


float RecursiviteQuickSort(int debut, int fin, int t[])
{
    int p ,i ,tmp, j;
    clock_t t1,t2;

    t1 = clock() ;

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

    if(i-debut-1 >= 1)
        RecursiviteQuickSort(debut, i-1, t);

    if(fin-(i+1) >= 1)
        RecursiviteQuickSort(i+1, fin, t);

    t2 = clock();
    return (float)(t2-t1)/CLOCKS_PER_SEC;
}

float Quick_sort(int tab[] ,int taille)
{
    return RecursiviteQuickSort(0, taille-1,tab);
}



