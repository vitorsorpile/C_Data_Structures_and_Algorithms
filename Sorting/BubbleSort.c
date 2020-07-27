#include <stdio.h>
#define TYPE int

void bubble_sort(TYPE *array, int len_array)
{
    if (!array) return;

    int i, j, tmp;

    for (i = len_array; i > 0; i--)
    {
        for (j = 0; j < i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {

                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    TYPE array[] = {15, 10, 67, -21, 0};
    int len_array = sizeof(array)/sizeof(TYPE);
    bubble_sort(array, len_array);

    for (int i = 0; i < len_array; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
    
    return 0;
}