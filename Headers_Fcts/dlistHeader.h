#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct celluleDouble
{
    int element;
    struct celluleDouble * suivant;
    struct celluleDouble * precedent;
};
typedef struct celluleDouble celluleDouble;

struct listeDouble
{
    celluleDouble * debut;
    celluleDouble * fin;
    unsigned longueur;
};
typedef struct listeDouble listeDouble;


#endif

int listeDoubleVide(listeDouble);
void affichageListeDouble(listeDouble);
void ajoutDebut(int, listeDouble *);
void ajoutFin(int,listeDouble *);
void suppressionDebut(listeDouble *);
void suppressionFin(listeDouble *);
void libererListeDouble(listeDouble);
