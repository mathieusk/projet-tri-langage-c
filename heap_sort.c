#include <stdio.h>
#include <stdlib.h>

#include "myFonction.h"

void placer(int g, int d, int *t)
{
    int i, j, x, place_trouvee;
    x=t[g];
    i=g;
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
            t[i]=t[j];
            i=j,
            j=2*i+1;
        }
    }
    t[i]=x;
}

int main()
{
    int tab[TAILLE_TAB];
    int g, d, tmp;

    InitTab(tab,TAILLE_TAB, NB_MAX);
    AfficherTab(tab,TAILLE_TAB);

    d=TAILLE_TAB-1;

    while(d>0)
    {
        g=(d+1)/2;
        while(g>0)
        {
            g--;
            placer(g,d,tab);
        }
        tmp=tab[0];
        tab[0]=tab[d];
        tab[d]=tmp;
        d--;
    }

    AfficherTab(tab, TAILLE_TAB);

    return 0;
}
