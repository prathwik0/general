#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[10];
    int *arr2;
    int *arr3;
    int *arr4;

    arr2 = (int *)malloc(10 * sizeof(int));
    arr3 = (int *)calloc(10, sizeof(int));

    arr4 = (int *)realloc(arr3, 20 * sizeof(int));
}