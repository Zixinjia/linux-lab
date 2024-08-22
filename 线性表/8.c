#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 双链表节点结构体
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// 初始化带头结点的循环双链表
void initList(Node *head)
{
    head->next = head;
    head->prev = head;
}

// 创建一个新节点
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 删除第一个值为 x 的节点
bool deleteNode(Node *head, int x)
{
    Node *p = head->next; // 从头节点的下一个开始
    while (p != head)
    { // 遍历直到回到头节点
        if (p->data == x)
        {
            // 更新前驱和后继指针
            p->prev->next = p->next;
            p->next->prev = p->prev;

            // 释放节点内存
            free(p);
            return true; // 成功删除节点
        }
        p = p->next; // 继续遍历下一个节点
    }
    return false; // 未找到值为 x 的节点
}

// 打印循环双链表
void printList(Node *head)
{
    Node *p = head->next;
    while (p != head)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node head;
    initList(&head);

    // 添加节点到循环双链表
    Node *node1 = createNode(10);
    Node *node2 = createNode(20);
    Node *node3 = createNode(30);

    head.next = node1;
    node1->prev = &head;
    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;
    node3->next = &head;
    head.prev = node3;

    printf("原链表: ");
    printList(&head);

    int x = 20;
    if (deleteNode(&head, x))
    {
        printf("删除值为 %d 的节点成功。\n", x);
    }
    else
    {
        printf("未找到值为 %d 的节点。\n", x);
    }

    printf("删除后的链表: ");
    printList(&head);

    return 0;
}
