#include <stdio.h>
#include <string.h>
void Sort(char (*strings)[100])
{
    int n = 10;
    char temp[100];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(strings[j], strings[j + 1]) > 0)
            {
                strcpy(temp, strings[j]);
                strcpy(strings[j], strings[j + 1]);
                strcpy(strings[j + 1], temp);
            }
        }
    }
}
int main()
{
    char strings[10][100];
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", strings[i]);
    }
    Sort(strings);
    for (int i = 0; i < 10; i++)
    {
        printf("str == %s\n", strings[i]);
    }
    return 0;
}