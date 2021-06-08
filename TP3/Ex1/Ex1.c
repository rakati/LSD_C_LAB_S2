#include "double.h"

listeDouble string_to_list(char** C){
    int l=strlen(C[1]);
    listeDouble P={NULL,NULL,0};
    for(int i=0;i<l;i++){
        ajoutDebut(C[1][l-1-i],&P);
    }
    return P;
}

bool palindrome(listeDouble P){
    unsigned l=P.longueur/2;
    listeDouble d=P,f=P;
    for(int i=0;i<l;i++){
        if(d.debut->element!=f.fin->element){
            return false;
        }
        d.debut=d.debut->suivant;
        f.fin=f.fin->precedent;
    }
    return true;
}

int main(int ac, char** av){
    listeDouble P = {NULL, NULL, 0};
    P=string_to_list(av);
    affichageListeDouble(P);
    if (palindrome(P)==true)
        printf("True\n");
    else
        printf("False\n");
    libererListeDouble(P);
    return 0;
}