#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main()
{
    char filename[50], new_filename[50];
    FILE *fp, *fp_out;
    int file_size, chunk_size, num_chunks, i, bytes_read;
    char buffer[BUF_SIZE];

    // 输入文件名
    scanf("%s", filename);

    // 获取文件大小
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("打开文件失败！\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    rewind(fp);

    printf("请输入每个分割文件的大小（字节）：");
    scanf("%d", &chunk_size);

    num_chunks = file_size / chunk_size + (file_size % chunk_size != 0);

    // 分割文件
    for (i = 1; i <= num_chunks; i++)
    {
        sprintf(new_filename, "%s_%d", filename, i);
        fp_out = fopen(new_filename, "wb");
        if (fp_out == NULL)
        {
            printf("打开文件 %s 失败！\n", new_filename);
            fclose(fp);
            return 1;
        }

        // 读取并写入分割文件
        while ((bytes_read = fread(buffer, 1, chunk_size, fp)) > 0)
        {
            fwrite(buffer, 1, bytes_read, fp_out);
        }

        fclose(fp_out);
    }

    fclose(fp);

    printf("文件分割完成！\n");

    return 0;
}