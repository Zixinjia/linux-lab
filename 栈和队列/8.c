#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

void processInput(char *input)
{
    char buffer[MAX_INPUT_SIZE];
    int index = 0;
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (ch == '#')
        {
            if (index > 0)
            {
                index--; // 删除前一个字符
            }
        }
        else if (ch == '@')
        {
            index = 0;
        }
        else
        {
            if (index < MAX_INPUT_SIZE - 1)
            {
                buffer[index++] = ch;
            }
        }
    }
    buffer[index] = '\0';

    printf("最终输入内容: %s\n", buffer);
}

int main()
{
    char input[MAX_INPUT_SIZE];
    printf("请输入内容（使用#进行退格，@清空内容）:\n");
    processInput(input);
    return 0;
}
