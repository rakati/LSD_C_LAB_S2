#include "double.h"



int listeDoubleVide(listeDouble L)
{
    if(L.debut==NULL)
        return 1;
    return 0;
}


void affichageListeDouble(listeDouble L)
{
    if(listeDoubleVide(L)==1)
    {
        printf("[]\n");
        return;
    }
    celluleDouble *temp=L.debut;
    printf("[");
    while(temp->suivant!=NULL)
    {
        printf("%c, ",temp->element);
        temp=temp->suivant;
    }
    if(temp!=NULL)
        printf("%c",temp->element);
    printf("]\n");
}



void ajoutDebut(char x,listeDouble * L)
{
    celluleDouble * C=(celluleDouble *)malloc(sizeof(celluleDouble));
    C->element=x;
    C->suivant=L->debut;
    C->precedent=NULL;
    
    if(listeDoubleVide(*L)==1)
    {
        L->debut=C;
        L->fin=C;
        L->longueur=1;
        return;
    }
    L->debut->precedent=C;
    L->debut=C;
    L->longueur+=1;
    return;
}


void ajoutFin(int x,listeDouble *L)
{
    celluleDouble * C=(celluleDouble *)malloc(sizeof(celluleDouble));
    C->element=x;
    C->precedent=L->fin;
    C->suivant=NULL;
    
    if(listeDoubleVide(*L)==1)
    {
        ajoutDebut(x,L);
        return;
    }
    L->fin->suivant=C;
    L->fin=C;
    L->longueur+=1;
    return;
}

void suppressionDebut(listeDouble * L)
{
    if(listeDoubleVide(*L)==1)
        return;
    if(L->longueur==1)
    {
        L->longueur=0;
        if(L->debut!=NULL)
            free(L->debut);
        L->debut=NULL;
        return;
    }
    celluleDouble * temp=L->debut;
    L->debut=L->debut->suivant;
    L->longueur-=1;
    free(temp);
    return;
}


void suppressionFin(listeDouble * L)
{
    if(listeDoubleVide(*L)==1)
        return;
    if(L->longueur==1)
    {
        suppressionDebut(L);
        return;
    }
    celluleDouble * temp=L->fin;
    L->fin=L->fin->precedent;
    L->fin->suivant=NULL;
    L->longueur-=1;
    free(temp);
    return;
}


void libererListeDouble(listeDouble L)
{
    while(L.debut!=NULL)
    {
        celluleDouble * temp=L.debut;
        L.debut=L.debut->suivant;
        free(temp);
    }
}