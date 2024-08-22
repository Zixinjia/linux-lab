#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef struct Stack
{
    int top;
    char items[MAX_STACK_SIZE];
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == (MAX_STACK_SIZE - 1);
}

void push(Stack *s, char item)
{
    s->items[++(s->top)] = item;
}

char pop(Stack *s)
{
    return s->items[(s->top)--];
}

char peek(Stack *s)
{
    if (isEmpty(s))
    {
        return '\0';
    }
    return s->items[s->top];
}

int isMatchingPair(char left, char right)
{
    return (left == '(' && right == ')') ||
           (left == '{' && right == '}') ||
           (left == '[' && right == ']');
}

int isBalanced(const char *expression)
{
    Stack s;
    initStack(&s);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(&s, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (isEmpty(&s) || !isMatchingPair(pop(&s), ch))
            {
                return 0;
            }
        }
    }

    return isEmpty(&s);
}

int main()
{
    char expression[MAX_STACK_SIZE];

    fgets(expression, MAX_STACK_SIZE, stdin);

    if (isBalanced(expression))
    {
        printf("成功\n");
    }
    else
    {
        printf("失败\n");
    }

    return 0;
}
