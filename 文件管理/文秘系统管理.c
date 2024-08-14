#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void split_file(char *filename)
{
    char new_filename[50];
    FILE *fp, *fp_out;
    int file_size, chunk_size, num_chunks, i, bytes_read;
    char buffer[BUF_SIZE];

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return;
    }
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    // 输入分割后的文件数量
    scanf("%d", &num_chunks);

    chunk_size = file_size / num_chunks;

    // 分割文件
    for (i = 1; i <= num_chunks; i++)
    {
        sprintf(new_filename, "%s_%d", filename, i);
        fp_out = fopen(new_filename, "wb");
        if (fp_out == NULL)
        {
            fclose(fp);
            return;
        }

        // 读取并写入分割文件
        while ((bytes_read = fread(buffer, 1, chunk_size, fp)) > 0)
        {
            fwrite(buffer, 1, bytes_read, fp_out);
        }

        fclose(fp_out);
    }

    fclose(fp);
}

void merge_files(char *filename)
{
    char new_filename[50], buffer[BUF_SIZE];
    FILE *fp, *fp_in;
    int bytes_read;

    // 打开第一个文件
    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        return;
    }

    while (1)
    {
        scanf("%s", new_filename);
        if (strcmp(new_filename, "end") == 0)
        {
            break;
        }

        fp_in = fopen(new_filename, "rb");
        if (fp_in == NULL)
        {
            fclose(fp);
            return;
        }

        // 读取并写入合并文件
        while ((bytes_read = fread(buffer, 1, BUF_SIZE, fp_in)) > 0)
        {
            fwrite(buffer, 1, bytes_read, fp);
        }

        fclose(fp_in);
    }

    fclose(fp);
}

int main()
{
    int choice;
    char filename[50];

    while (1)
    {
        printf("请选择操作：\n");
        printf("1：文件拆分\n");
        printf("2：文件合并\n");
        printf("3：退出系统\n");
        printf("请输入您的选择：");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("请输入要拆分的文件名：");
            scanf("%s", filename);
            split_file(filename);
            break;
        case 2:
            scanf("%s", filename);
            merge_files(filename);
            break;
        case 3:
            printf("退出系统！\n");
            return 0;
        }
    }

    return 0;
}