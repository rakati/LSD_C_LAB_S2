#include "Ex2Arr.h"

void printArray(int arr[],int n){
    printf("[ ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("]\n");
}

int Randoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void sortArray(int arr[], int n){
    int s;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                s=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=s;
            }
        }
    }
    return ;
}

int NotDuplicates(int arr[], int n){
    int c=0,i=0;
    while(i<n){
        if(arr[i]!=arr[i+1]){
            c++;
            i++;
        }
        else{
            i++;
        }
    }
    return c;
}

int* removeDuplicates(int arr[],int n, int c){
    int* Arr=(int*)malloc(c*sizeof(int));
    int m=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[i+1]){
            Arr[m]=arr[i];
            m+=1;
        }
    }
    return Arr;
}

int* mergeArray(int arr1[], int n1, int arr2[], int n2){
    int* Arr=(int*)malloc((n1+n2)*sizeof(int));
    for(int i=0;i<n1+n2;i++){
        if(i<n1)
            Arr[i]=arr1[i];
        else
            Arr[i]=arr2[i-n1];
    }
    return Arr;
}