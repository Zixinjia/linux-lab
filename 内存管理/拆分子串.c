#include <stdio.h>
#include <string.h>

void split_strings(int n, char strings[][100])
{
    for (int i = 0; i < n; i++)
    {
        char result[100] = "";
        int len = strlen(strings[i]);

        for (int j = 0; j < len; j += 8)
        {
            strncat(result, strings[i] + j, 8);
            if (strlen(result) < 8)
                strcat(result, "00000000");
            printf("%s\n", result);
            result[0] = '\0';
        }
    }
}

int main()
{
    int n;
    printf("输入字符串个数：");
    scanf("%d", &n);

    char strings[100][100];
    for (int i = 0; i < n; i++)
    {
        printf("输入字符串%d：", i + 1);
        scanf("%s", strings[i]);
    }

    split_strings(n, strings);

    return 0;
}