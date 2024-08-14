#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fileA, *fileB, *fileC;
    char contentA[100], contentB[100], merged[200];

    fileA = fopen("A.txt", "r");
    fileB = fopen("B.txt", "r");
    fileC = fopen("C.txt", "w");

    if (fileA == NULL || fileB == NULL || fileC == NULL)
    {
        printf("无法打开文件。\n");
        return 1;
    }

    fgets(contentA, sizeof(contentA), fileA);
    fgets(contentB, sizeof(contentB), fileB);

    strcpy(merged, contentA);
    strcat(merged, contentB);

    int len = strlen(merged);
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (merged[i] > merged[j])
            {
                char temp = merged[i];
                merged[i] = merged[j];
                merged[j] = temp;
            }
        }
    }

    fputs(merged, fileC);

    fclose(fileA);
    fclose(fileB);
    fclose(fileC);
    return 0;
}