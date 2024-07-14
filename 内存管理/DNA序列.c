#include <stdio.h>
#include <string.h>

void find_max(char *seq, int len, int sub_len, char *res)
{
    float max_ratio = 0;
    int seq_len = strlen(seq);

    for (int i = 0; i <= seq_len - sub_len; i++)
    {
        int gc_count = 0;
        for (int j = i; j < i + sub_len; j++)
        {
            if (seq[j] == 'G' || seq[j] == 'C')
            {
                gc_count++;
            }
        }

        float gc_ratio = (float)gc_count / sub_len;

        if (gc_ratio > max_ratio)
        {
            max_ratio = gc_ratio;
            strncpy(res, seq + i, sub_len);
            res[sub_len] = '\0';
        }
    }
}

int main()
{
    char res[100];
    char seq[100];
    int sub_len;

    printf("基因序列：");
    scanf("%s", seq);
    printf("子序列：");
    scanf("%d", &sub_len);

    find_max(seq, strlen(seq), sub_len, res);

    printf("%s\n", res);

    return 0;
}