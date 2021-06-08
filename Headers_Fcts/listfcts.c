#include "listHeader.h"


int testVide(liste L)
{
    if(L==NULL)
        return 1;
    return 0;
}

unsigned longueur(liste L)
{
    unsigned l=0;
    if(testVide(L)==0)
    {
        liste temp=L;
        while(temp!=NULL)
        {
            l+=1;
            temp=temp->suivant;
        }
    }
    return l;
}

void affichageListe(liste L)
{
    if(L==NULL)
        printf("[ ]");
    else
    {
        printf("[");
        liste temp=L;
        while(temp->suivant!=NULL)
        {
            printf("%d, ",temp->element);
            temp=temp->suivant;
        }
        if(temp!=NULL)
            printf("%d",temp->element);
        printf("]\n");
    }
}

void ajoutDebut(int x,liste * L)
{
    cellule * C=(cellule *)malloc(sizeof(cellule));
    C->element=x;
    C->suivant=*L;
    *L=C;
    return;
}

void ajoutFin(int x,liste * L)
{
    liste C=(liste)malloc(sizeof(cellule));
    C->element=x;
    C->suivant=NULL;
    if(*L==NULL)
        *L=C;
    else
    {
        liste temp=*L;
        while(temp->suivant!=NULL)
            temp=temp->suivant;
        temp->suivant=C;
    }
    return;
}

void suppressionDebut(liste * L)
{
    if(L!=NULL)
    {
        liste temp=*L;
        *L=(*L)->suivant;
        free(temp);
    }
    return;
}

void suppressionFin(liste * L)
{
    if(L==NULL)
    {
        return;
    }
    if((*L)->suivant==NULL)
    {
        free(*L);
        *L=NULL;
    }
    else
    {
        liste temp=*L;
        liste temp_1=*L;
        while(temp->suivant!=NULL)
        {
            temp_1=temp;
            temp=temp->suivant;
        }
        temp_1->suivant=NULL;
        free(temp);
    }
    return;
}

void liberer(liste L)
{
    while(L!=NULL)
    {
        liste temp=L;
        L=L->suivant;
        free(temp);
    }
}
