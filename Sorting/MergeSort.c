#include <stdio.h>
#define TYPE int

void merge(TYPE *array, int start, int mid, int end)
{
    int a = start, b = mid + 1, i;
    TYPE tmp[end - start + 1];
    
    for (i = 0; a < mid + 1 && b < end + 1; i++)
    {
        if (array[a] < array[b])
        {   
            tmp[i] = array[a];
            a++;
            continue;
        }

        tmp[i] = array[b];
        b++;
    }

    for (; a < mid + 1; a++, i++)
    {
        tmp[i] = array[a];
    }

    for (; b < end + 1; b++, i++)
    {
        tmp[i] = array[b];
    }

    for (i = start; i < end + 1; i++)
    {   
        array[i] = tmp[i - start];
    }
}

void merge_sort(TYPE *array, int start, int end)
{   
    if (end <= start) return;

    int mid = (end + start)/2;
    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);

    merge(array, start, mid, end);
}

int main()
{
    TYPE array[] = {15, 10, 67, -21, 0};
    int len_array = sizeof(array)/sizeof(TYPE);
    
    merge_sort(array, 0, len_array - 1);

    for (int i = 0; i < len_array; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");

    return 0;
}