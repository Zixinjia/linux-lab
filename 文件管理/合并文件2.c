#include <stdio.h>

int main()
{
    FILE *file1, *file2, *mergedFile;
    char content1[100], content2[100];

    file1 = fopen("file1.txt", "r");
    file2 = fopen("file2.txt", "r");
    mergedFile = fopen("merged.txt", "w");

    if (file1 == NULL || file2 == NULL || mergedFile == NULL)
    {
        printf("无法打开文件。\n");
        return 1;
    }

    fgets(content1, sizeof(content1), file1);
    fgets(content2, sizeof(content2), file2);

    fputs(content1, mergedFile);
    fputs(content2, mergedFile);

    fclose(file1);
    fclose(file2);
    fclose(mergedFile);
    return 0;
}