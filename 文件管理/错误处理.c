#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[50], ch;
    FILE *fp;

    // 输入文件名
    scanf("%s", filename);

    fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        printf("打开文件失败！\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\t')
        {
            fprintf(fp, "    ");
            if (ferror(fp))
            {
                printf("写入文件错误！\n");
                fclose(fp);
                return 1;
            }
        }
        else
        {
            fputc(ch, fp);
            if (ferror(fp))
            {
                printf("写入文件错误！\n");
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);

    return 0;
}