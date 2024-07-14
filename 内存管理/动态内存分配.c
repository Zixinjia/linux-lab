#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    int *arr = (int *)malloc(num * sizeof(int));
    if (arr == NULL)
    {
        printf("内存分配失败.\n");
        return 1;
    }

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, num);

    for (int i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);

    return 0;
}