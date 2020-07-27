#include <stdio.h>
#define TYPE int

void selection_sort(TYPE *array, int len_array)
{
    if (!array) return;

    for (int i = 0; i < len_array - 1; i++)
    {
        int lowest = array[i];
        int position = i;

        for (int j = i + 1; j < len_array; j++)
        {
            if (array[j] < lowest)
            {
                lowest = array[j];
                position = j;
            }
        }

        if (position != i)
        {
            int tmp = array[i];
            array[i] = array[position];
            array[position] = tmp;
        }
    }
}

int main()
{
    TYPE array[] = {15, 10, 67, -21, 0};
    int len_array = sizeof(array)/sizeof(TYPE);
    selection_sort(array, len_array);

    for (int i = 0; i < len_array; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
    
    return 0;
}