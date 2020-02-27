#ifndef MYFONCTION_H
#define MYFONCTION_H

#define TAILLE_TAB 50000
#define NB_MAX 10000

int NbrRandom(int max);
void InitTab(int tab[], int tailleTab, int nbrMax);
void CopyTab(int ori[], int tmp[], int tailleTab);
void AfficherTab(int* tab, int tailleTab);
int IsSorted(int tab[], int taille);

float TriParInsertion(int tab[] ,int taille);
float TriParSelection(int t[] ,int taille);
float TriParEchange(int tab[] ,int taille);
float ShakeSort(int tab[] ,int taille);
float HeapSort(int tab[] ,int taille);
float ShellSort(int tab[] ,int taille);
float Quick_sort(int tab[] ,int taille);

#endif
