#include <stdio.h>

int main()
{
    char input[100];
    FILE *file;

    printf("请输入一个字符串: ");
    fgets(input, sizeof(input), stdin);

    file = fopen("test.txt", "w");
    if (file == NULL)
    {
        printf("无法打开文件。\n");
        return 1;
    }

    for (int i = 0; input[i] != '\0'; i++)
    {
        fputc(toupper(input[i]), file);
    }

    fclose(file);
    return 0;
}