#include "double.h"

void sort_list(listeDouble* P){
    int i,j,k;
    listeDouble temp=*P, temp2=*P;
    while(temp.debut->suivant!=NULL){
        while(temp2.debut->suivant!=NULL){
            if(temp.debut->element>temp2.debut->suivant->element){
                k=temp.debut->element;
                temp.debut->element=temp2.debut->suivant->element;
                temp2.debut->suivant->element=k;
            }
            temp2.debut=temp2.debut->suivant;
        }
        temp.debut=temp.debut->suivant;
        temp2=temp;
    }
    return;
}

void merge_lists(listeDouble* P,listeDouble * L){
    listeDouble temp=*P;
    temp.fin->suivant=(*L).debut;
    return;
}

void remove_duplicated(listeDouble* L){
    listeDouble temp=*L;
    listeDouble temp2=*L;
    while(temp.debut->suivant!=NULL){
        if(temp.debut->element==temp.debut->suivant->element){
            if(temp.debut->suivant->suivant==NULL){
                temp2.debut=temp.debut;
                temp.debut->suivant=NULL;
                temp2.debut=temp2.debut->suivant;
                free(temp2.debut);
                return;
            }
            else{
                temp2.debut=temp.debut;
                temp2.debut=temp2.debut->suivant;
                temp.debut->suivant=temp.debut->suivant->suivant;
                temp2.debut->suivant=NULL;
                free(temp2.debut);
            }
        }
        else{
            temp.debut=temp.debut->suivant;
        }
    }
}

int Randoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
  

int main(){
    listeDouble P={NULL,NULL,0};
    listeDouble L={NULL,NULL,0};
    srand(time(0));
    for (int i=0;i<100;i++){
        ajoutDebut(Randoms(0,40),&P);
    }
    printf("List P: ");
    affichageListeDouble(P);
    for (int i=0;i<30;i++){
        ajoutDebut(Randoms(0,40),&L);
    }
    printf("List L: ");
    affichageListeDouble(L);
    merge_lists(&P,&L);
    printf("List P merged with L: ");
    affichageListeDouble(P);
    sort_list(&P);
    printf("List P: ");
    affichageListeDouble(P);
    remove_duplicated(&P);
    printf("List P without doubles: ");
    affichageListeDouble(P);
    libererListeDouble(P);
    return 0;
}