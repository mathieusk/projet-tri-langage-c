#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#include "myFonction.h"

typedef float (*fPtr)(int*, int);

typedef struct resultatTri{
    char* nomTri;
    char* cout;
    float tpsTrie[3];

    float tpsDesor[3];

    fPtr fonction;
}RESULTATS;

int main()
{
    int tabOrigine[TAILLE_TAB], tabTemp[TAILLE_TAB], longeurTab[3]={500,1000,10000};
    RESULTATS res[7];

    res[0].nomTri="Tri par insertion";
    res[0].cout="O(n^2)    ";
    res[0].fonction = &TriParInsertion;

    res[1].nomTri="Tri par selection";
    res[1].cout="O(n^2)    ";
    res[1].fonction = &TriParSelection;

    res[2].nomTri="Tri par echange  ";
    res[2].cout="O(n^2)    ";
    res[2].fonction = &TriParEchange;

    res[3].nomTri="Shake sort       ";
    res[3].cout="O(n^2)    ";
    res[3].fonction= &ShakeSort;

    res[4].nomTri="Shell sort       ";
    res[4].cout="O(n^1,2)  ";
    res[4].fonction=&ShellSort;

    res[5].nomTri="Heap sort        ";
    res[5].cout="O(n log n)";
    res[5].fonction=&HeapSort;

    res[6].nomTri="Quick sort       ";
    res[6].cout="O(n log n)";
    res[6].fonction=&Quick_sort;

    printf("                                |               Tableaux deja tries              |                     Tableaux                   \n");
    printf("                                |                                                |              aleatoirement desordonnes         \n");
    printf("                                |                                                |              (moyenne sur 10 tableaux)         \n");
    printf("                                |________________________________________________|________________________________________________\n");
    printf("                                |    500 elts   |   1 000 elts  |   10 000 elts  |  500 elts    |   1 000 elts  |   10 000 elts  |\n");
    printf("________________________________|_______________|_______________|________________|______________|_______________|________________|\n");


    //boucle de test sur tableau desordonées de toutes les longueurs
    for(int l=0; l<3; l++)
    {
        // test des tris sur 10 tab differents
        for(int rep=0; rep<10; rep++)
        {
            InitTab(tabOrigine,longeurTab[l], NB_MAX);
            // test avec meme tableau sur tous les tris
            for(int i=0; i<7; i++)
            {
                CopyTab(tabOrigine, tabTemp, longeurTab[l]);
                //AfficherTab(tabTemp, longeurTab[l]);
                res[i].tpsDesor[l]+=((res[i].fonction)(tabTemp, longeurTab[l]))/10;
                //AfficherTab(tabTemp, longeurTab[l]);
                if(!IsSorted(tabTemp, longeurTab[l])) exit(0);
                //assert(IsSorted(tabTemp, longeurTab[l])==0);
            }
        }
    }

    // test des tris sur tableau ordonées
    for(int l=0; l<3; l++)
    {
            for(int i=0; i<7; i++)
            {
                res[i].tpsTrie[l]+=((res[i].fonction)(tabTemp, longeurTab[l]));
                if(!IsSorted(tabTemp, longeurTab[l])) exit(0);
                //assert(IsSorted(tabTemp, longeurTab[l])==0);
            }
    }

    for(int i=0; i<7; i++)
        printf("%s    |%s|    %.5f    |    %.5f    |    %.5f    |    %.5f    |    %.5f    |    %.5f    |\n",res[i].nomTri,res[i].cout,res[i].tpsTrie[0],
                                                                                                            res[i].tpsTrie[1],res[i].tpsTrie[2],
                                                                                                            res[i].tpsDesor[0], res[i].tpsDesor[1],
                                                                                                            res[i].tpsDesor[2]);

    return 0;
}
