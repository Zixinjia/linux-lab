#include <stdio.h>
#include <string.h>

int isPalindrome(const char *str)
{
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right)
    {
        while (left < right && !isalnum(str[left]))
        {
            left++;
        }
        while (left < right && !isalnum(str[right]))
        {
            right--;
        }

        if (tolower(str[left]) != tolower(str[right]))
        {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

int main()
{
    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str))
    {
        printf("是回文。\n");
    }
    else
    {
        printf("不是回文。\n");
    }

    return 0;
}
