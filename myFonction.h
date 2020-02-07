#ifndef MYFONCTION_H
#define MYFONCTION_H

#define TAILLE_TAB 10
#define NB_MAX 10

int NbrRandom(int max);
void InitTab(int* tab, int tailleTab, int nbrMax);
void TrierTab(int* tab, int tailleTab);
void AfficherTab(int* tab, int tailleTab);

#endif
