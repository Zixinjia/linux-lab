#include <stdio.h>
#include <string.h>

void Bubble_Sort(char str[][100], int n)
{
    char temp[100];
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(str[j], str[j + 1]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }
}
int main()
{
    char str[100][100];
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }
    Bubble_Sort(*str, n);
    for (i = 0; i < n; i++)
    {
        printf("%s\n", str[i]);
    }
    return 0;
}
