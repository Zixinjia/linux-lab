#include <stdio.h>
#include <stdlib.h>

// 链队列节点结构体
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

// 初始化链队列
void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

// 入队
void enqueue(Queue *q, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 出队
int dequeue(Queue *q)
{
    if (q->front == NULL)
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

// 遍历
void traverseQueue(Queue *q)
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
    q->front = q->rear = NULL;
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("队列内容: ");
    traverseQueue(&q);

    printf("出队元素: %d\n", dequeue(&q));

    printf("队列内容: ");
    traverseQueue(&q);

    destroyQueue(&q);

    return 0;
}
