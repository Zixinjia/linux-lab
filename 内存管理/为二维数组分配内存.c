#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row;
    int col;
    scanf("%d%d", &row, &col);
    int **p = (int **)malloc(row * sizeof(int *));
    if (p == NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }

    for (int i = 0; i < row; i++)
    {
        p[i] = (int *)malloc(col * sizeof(int));
        if (p[i] == NULL)
        {
            printf("内存分配失败\n");
            return 1;
        }
    }
    int count = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            p[i][j] = count++;
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row; i++)
    {
        free(p[i]);
    }
    free(p);

    return 0;
}