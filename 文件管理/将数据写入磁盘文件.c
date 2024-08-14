#include <stdio.h>

int main()
{
    FILE *file = fopen("output.txt", "w");

    if (file == NULL)
    {
        printf("无法打开文件。\n");
        return 1;
    }

    fputs("好好学习，天天向上#", file);

    fclose(file);
    return 0;
}