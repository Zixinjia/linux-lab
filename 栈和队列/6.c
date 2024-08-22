#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void initStack(Stack *s)
{
    s->top = NULL;
}

int isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("栈为空\n");
        exit(1);
    }
    Node *temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

// 逆序
void reverseStack(Stack *s)
{
    Stack aux;
    initStack(&aux);

    while (!isEmpty(s))
    {
        push(&aux, pop(s));
    }

    while (!isEmpty(&aux))
    {
        push(s, pop(&aux));
    }
}

// 打印栈
void printStack(Stack *s)
{
    Node *current = s->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 销毁栈
void destroyStack(Stack *s)
{
    Node *current = s->top;
    Node *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main()
{
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("原始栈内容: ");
    printStack(&s);

    // 逆序
    reverseStack(&s);

    printf("逆序栈内容: ");
    printStack(&s);

    destroyStack(&s);

    return 0;
}
