#include <stdio.h>
#include <stdlib.h>

#include "myFonction.h"

int main()
{
    //int* p = malloc(sizeof(int)) ; // tableau des pas
    //int t=1; // taille tableau des pas
    //int m=0

    int tmp=0, j=0, i=0;
    int tab[TAILLE_TAB];
    int pas;

    InitTab(tab,TAILLE_TAB, NB_MAX);
/*
    p[0]=1;
    while ( (3*p[0]+1) < TAILLE_TAB )
    {
        t++;
        p = realloc(p, t*sizeof(int));

        for(int i = t-1 ; i>0 ; i--)
            p[i]=p[i-1];

        p[0] = 3*p[1]+1;
    }
    printf("tableau des pas\n");
    AfficherTab( p, t );
    printf("\n");
*/

    //recherche du pas max.
    pas=1;
    while ( 3*pas+1 < TAILLE_TAB )
        pas = 3*pas+1;
    printf("pas max = %d \n",pas);

    AfficherTab(tab,TAILLE_TAB);
    printf("\n");

    while(pas>=1)
    {
        // boucle pour faire le décalage de 1 sur le pas et donc créer les différents tableaux possible pour chaque pas.
        for(j=0; j<pas; j++)
        {
            // si le pas plus le décalage sup au tab on sort de la boucle, plus de tableau possible avec ce pas.
            if(pas+j >= TAILLE_TAB)
                break;
            printf("j=%d \n",j) ;
            // tri par insertion simple mais réaliser avec le pas plus le déclage
            for(int k = pas+j ; k < TAILLE_TAB; k+=pas)
            {
                i=k;
                tmp=tab[k];
                while( i-pas>=0 && tmp<tab[i-pas] )
                {
                    printf("[T%d ",i-pas);
                    printf("T%d ",i);
                    tab[i]=tab[i-pas];
                    i-=pas;
                }
                tab[i]=tmp;
                printf("] ");
            }
            printf("\n");
        }
        AfficherTab(tab,TAILLE_TAB);
        printf("\n");
        pas = (pas-1)/3;
        //m++;
    }

    return 0;
}
