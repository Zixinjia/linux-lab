#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 32

typedef struct Stack
{
    int top;
    int items[MAX_STACK_SIZE];
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

void push(Stack *s, int item)
{
    if (isFull(s))
    {
        return;
    }
    s->items[++(s->top)] = item;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return s->items[(s->top)--];
}

void printBinary(int N)
{
    if (N == 0)
    {
        printf("0");
        return;
    }

    Stack s;
    initStack(&s);

    while (N > 0)
    {
        push(&s, N % 2);
        N = N / 2;
    }

    while (!isEmpty(&s))
    {
        printf("%d", pop(&s));
    }
}

int main()
{
    int number;

    scanf("%d", &number);

    if (number < 0)
    {
        return 1;
    }

    printBinary(number);

    return 0;
}
