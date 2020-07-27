#include <stdio.h>
#define TYPE int

void insertion_sort(TYPE *array, int len_array)
{   
    if (!array) return;

    int i, j, key;
    for (i = 1; i < len_array; i++)
    {
        key = array[i];

        for (j = i; j > 0 && array[j - 1] > key; j--)
        {
            array[j] = array[j - 1];
        }
        array[j] = key;
    }
}

int main()
{
    TYPE array[] = {15, 10, 67, -21, 0};
    int len_array = sizeof(array)/sizeof(TYPE);
    insertion_sort(array, len_array);

    for (int i = 0; i < len_array; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");

    return 0;
}