#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
    }
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("队列为空\n");
        exit(1);
    }
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void initStack(Stack *s)
{
    s->top = NULL;
}

int isStackEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, int data)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
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
    if (isStackEmpty(s))
    {
        printf("栈为空\n");
        exit(1);
    }
    StackNode *temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

// 逆序存储队列
void reverseQueue(Queue *q)
{
    Stack s;
    initStack(&s);

    while (!isQueueEmpty(q))
    {
        push(&s, dequeue(q));
    }

    while (!isStackEmpty(&s))
    {
        enqueue(q, pop(&s));
    }
}

void printQueue(Queue *q)
{
    Node *current = q->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void destroyQueue(Queue *q)
{
    Node *current = q->front;
    Node *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void destroyStack(Stack *s)
{
    StackNode *current = s->top;
    StackNode *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("原队列内容: ");
    printQueue(&q);

    // 逆序
    reverseQueue(&q);

    printf("逆序队列内容: ");
    printQueue(&q);

    destroyQueue(&q);

    return 0;
}
