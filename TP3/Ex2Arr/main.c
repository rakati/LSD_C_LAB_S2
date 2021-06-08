#include "Ex2Arr.h"

int main(){
    int Arr1[100], Arr2[30];
    srand(time(0));
    for(int i=0;i<100;i++){
        Arr1[i]=Randoms(0,10);
    }
    printf("Arr1= ");
    printArray(Arr1,100);
    for(int i=0;i<30;i++){
        Arr2[i]=Randoms(0,20);
    }
    printf("Arr2= ");
    printArray(Arr2,30);
    int* Arr=mergeArray(Arr1,100,Arr2,30);
    printf("Merged arrays : ");
    printArray(Arr,130);
    sortArray(Arr,130);
    printf("Sorted Array :");
    printArray(Arr,130);
    int n=NotDuplicates(Arr,130);
    int* Arr3=removeDuplicates(Arr,130,n);
    printf("Array without duplicates : ");
    printArray(Arr3,n);
    free(Arr3);
    return 0;
}