#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **splitstr(char *src, char ch)
{
    int count = 0;
    char *temp = src;

    // 第一次遍历，计算单词的数量
    while (*temp)
    {
        if (*temp == ch)
        {
            count++;
        }
        temp++;
    }
    count++; // 最后一个单词的数量

    // 分配指针数组
    char **result = (char **)malloc((count + 1) * sizeof(char *));
    if (result == NULL)
    {
        return NULL; // 分配失败
    }

    int index = 0;
    char *start = src;

    // 第二次遍历，分配每个单词的内存并复制
    while (*src)
    {
        if (*src == ch)
        {
            int len = src - start;
            result[index] = (char *)malloc((len + 1) * sizeof(char));
            if (result[index] == NULL)
            {
                // 如果分配失败，释放已经分配的内存
                for (int i = 0; i < index; i++)
                {
                    free(result[i]);
                }
                free(result);
                return NULL;
            }
            strncpy(result[index], start, len);
            result[index][len] = '\0';
            index++;
            start = src + 1;
        }
        src++;
    }

    // 处理最后一个单词
    int len = src - start;
    result[index] = (char *)malloc((len + 1) * sizeof(char));
    if (result[index] == NULL)
    {
        for (int i = 0; i < index; i++)
        {
            free(result[i]);
        }
        free(result);
        return NULL;
    }
    strncpy(result[index], start, len);
    result[index][len] = '\0';
    index++;

    // 最后一个元素置为NULL，表示结束
    result[index] = NULL;

    return result;
}

int main()
{
    const int N = 100;
    char *src = (char *)malloc(N * sizeof(char));
    if (src == NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }

    printf("请输入字符串: ");
    if (fgets(src, N, stdin) == NULL)
    {
        printf("输入错误\n");
        free(src);
        return 1;
    }

    // 移除换行符
    size_t len = strlen(src);
    if (len > 0 && src[len - 1] == '\n')
    {
        src[len - 1] = '\0';
    }

    char **dest = splitstr(src, ' ');

    if (dest == NULL)
    {
        printf("内存分配失败\n");
        free(src);
        return 1;
    }

    // 打印分隔后的单词
    for (int i = 0; dest[i] != NULL; i++)
    {
        printf("%s\n", dest[i]);
        free(dest[i]); // 释放每个单词的内存
    }
    free(dest); // 释放存储单词指针的数组
    free(src);  // 释放源字符串

    return 0;
}