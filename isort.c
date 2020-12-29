#include <stdio.h>

#define ARRSIZE 50

void shift_element(int *arr, int i)
{
    if (i == 0 || arr == NULL)
        return;
    int prev, next;
    prev = *(arr);
    for (size_t j = 1; j <= i; j++)
    {
        next = *(arr + j);
        *(arr + j) = prev;
        prev = next;
    }
}

void insertion_sort(int *arr, int len)
{
    if (len == 1 || arr == NULL) return;
    int tmp;
    for (size_t i = 1; i < len; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (*(arr + i) < *(arr + j))
            {
                tmp = *(arr + i);
                shift_element(arr + j, i - j);
                *(arr + j) = tmp;
            }
        }
    }
}

int main()
{
    int arr[ARRSIZE];
    int mone = 0;
    int num;
    while (mone < ARRSIZE)
    {
        if (0 < scanf(" %d",&num)){
            *(arr+mone)=num;
            mone++;
        }
    }
    insertion_sort(arr, ARRSIZE);
    for (size_t i = 0; i < ARRSIZE; i++)
    {
        printf("%d", *(arr + i));
        if (i != ARRSIZE - 1)
            printf(",");
    }
    printf("\n");
    return 0;
}