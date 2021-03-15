#include "header.h"

/*
** Hint: for finding the largest third element in the array you don't need
** to sort the whole array, only three variables is needed for this purpose
** and the algorithm comlexity will be O(n).
*/
int     get_third_largest(int *tab, int size)
{
    int p=0,q=0,r=0;
    srand(time(0));
    for(int i=0;i<1000;i++){
        array[i]=rand();
        if (array[i]>p){
            r=q;
            q=p;
            p=array[i];
        }
        if (array[i]>q && array[i]<p){
            r=q;
            q=array[i];
        }
        if (array[i]>r && array[i]<q){
            r=array[i];
        }
    }
    return r;
}
