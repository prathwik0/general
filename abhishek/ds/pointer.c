#include <stdio.h>

int main()
{
    int arr[] = {1, 10, 69, 99};

    int *pointer = arr;

    for (int i = 0; i < 4; i++)
    {
        printf("%d -- %d and %d\n", i, arr[i], *pointer);
        pointer++;
    }

    return 0;
}