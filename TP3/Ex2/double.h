#ifndef DOUBLE_H
#define DOUBLE_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
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

int listeDoubleVide(listeDouble);
void affichageListeDouble(listeDouble);
void ajoutDebut(char, listeDouble *);
void ajoutFin(int,listeDouble *);
void suppressionDebut(listeDouble *);
void suppressionFin(listeDouble *);
void libererListeDouble(listeDouble);

#endif