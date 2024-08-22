#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int items[MAX_QUEUE_SIZE];
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue *q)
{
    return q->size == 0;
}

int isFull(Queue *q)
{
    return q->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue *q, int item)
{
    if (isFull(q))
    {
        printf("队列已满\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = item;
    q->size++;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空\n");
        return -1; // 返回无效值
    }
    int item = q->items[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    return item;
}

void traverseQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("队列为空\n");
        return;
    }
    int i = q->front;
    int count = q->size;
    while (count > 0)
    {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
        count--;
    }
    printf("\n");
}

int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("入队后的队列: ");
    traverseQueue(&q);

    printf("出队: %d\n", dequeue(&q));
    printf("出队: %d\n", dequeue(&q));

    printf("出队后的队列: ");
    traverseQueue(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("再次入队后的队列: ");
    traverseQueue(&q);

    return 0;
}
