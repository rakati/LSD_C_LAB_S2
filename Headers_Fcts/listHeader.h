#ifndef HEADER
#define HEADER

#include<stdio.h>
#include<stdlib.h>
//#include "liste_simple.h"

struct cellule
{
    int element;
    struct cellule * suivant;

};
typedef struct cellule cellule;
typedef struct cellule * liste;

#endif

int testVide(liste);
unsigned longueur(liste);
void affichageListe(liste);
void ajoutDebut(int,liste *);
void ajoutFin(int,liste *);
void suppressionDebut(liste *);
void suppressionFin(liste *);
void liberer(liste);
