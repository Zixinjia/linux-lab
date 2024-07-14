#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    int *arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    printf("数组元素：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);

    return 0;
}