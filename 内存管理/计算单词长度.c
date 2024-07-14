#include <stdio.h>
#include <string.h>

int lastWordLength(const char *str)
{
    int len = 0;
    const char *start = NULL;
    const char *curr = str;

    while (*curr)
    {
        if (*curr != ' ' && (curr == str || *(curr - 1) == ' '))
        {
            start = curr;
        }
        curr++;
    }

    if (start)
    {
        len = strlen(start);
    }

    return len;
}

int main()
{
    char input[5001];

    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    int length = lastWordLength(input);

    printf("最后一个单词长度为: %d\n", length);

    return 0;
}