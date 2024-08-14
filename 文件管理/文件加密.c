#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main()
{
    char filename[50], new_filename[50], password[50];
    FILE *fp, *fp_out;
    int ch, i;

    scanf("%s", filename);

    scanf("%s", password);

    scanf("%s", new_filename);

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return 1;
    }

    fp_out = fopen(new_filename, "wb");
    if (fp_out == NULL)
    {
        fclose(fp);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        ch ^= password[i % strlen(password)];
        i++;
        fputc(ch, fp_out);
    }

    fclose(fp);
    fclose(fp_out);

    return 0;
}