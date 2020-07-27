#include <stdio.h>
#define TYPE int

int partition(TYPE *array, int start, int end)
{
    int pivot = array[start];
    int i = start + 1, j = end;
    TYPE tmp;
    while (1)
    {
        while (i < end && array[i] < pivot) i++;
        while (j > start && array[j] > pivot) j--;
        
        if (i >= j)
        {
            array[start] = array[j];
            array[j] = pivot; 
            return j;
        } 
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;

    }
}

void quick_sort(TYPE *array, int start, int end)
{   
    if (end <= start) return;
    
    int partition_index = partition(array, start, end);
    quick_sort(array, start, partition_index);
    quick_sort(array, partition_index + 1, end);

}

int main()
{
    TYPE array[] = {15, 10, 67, -21, 0};
    int len_array = sizeof(array)/sizeof(TYPE);
    quick_sort(array, 0, len_array - 1);

    for (int i = 0; i < len_array; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");

    return 0;
}