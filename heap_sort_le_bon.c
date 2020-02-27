#include <stdio.h>
#include <stdlib.h>

#include "myFonction.h"

void placer(int g, int d, int *t)
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

int main()
{
    int tab[TAILLE_TAB];
    int g, d, tmp;

    InitTab(tab,TAILLE_TAB, NB_MAX);
    AfficherTab(tab,TAILLE_TAB);

    d=TAILLE_TAB-1;
    g=(d+1)/2;
    while(g>0)
    {
        g--;
        placer(g,d,tab);
    }
    while(d>1)
    {
        tmp=tab[0];
        tab[0]=tab[d];
        tab[d]=tmp;
        d--;
        // quand il ne reste que 2 elements dans le tableau pas besoin d appeler la methode placer.
        if(d>1)
            placer(g,d,tab);
    }
    if(tab[0]>tab[1])
    {
        tmp=tab[0];
        tab[0]=tab[1];
        tab[1]=tmp;
    }

    AfficherTab(tab, TAILLE_TAB);

    return 0;
}
