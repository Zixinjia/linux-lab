#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char filename[50], str[MAX_LEN];
    FILE *fp;
    // 输入文件名
    scanf("%s", filename);
    // 输入字符串
    scanf("%s", str);
    // 将字符串写入文件
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("打开文件失败！\n");
        return 1;
    }
    fprintf(fp, "%s\n", str);
    fclose(fp);

    // 从文件读取字符串
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("打开文件失败！\n");
        return 1;
    }
    fgets(str, MAX_LEN, fp);
    fclose(fp);

    // 显示字符串
    printf("从文件中读取的字符串：%s\n", str);

    return 0;
}