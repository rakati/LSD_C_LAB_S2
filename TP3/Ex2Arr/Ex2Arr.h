#ifndef EX2ARR_H
#define EX2ARR_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int arr[],int n);
int Randoms(int lower, int upper);
void sortArray(int arr[], int n);
int NotDuplicates(int arr[], int n);
int* removeDuplicates(int arr[],int n, int c);
int* mergeArray(int arr1[], int n1, int arr2[], int n2);

#endif