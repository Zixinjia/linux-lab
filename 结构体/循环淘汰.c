<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int id;
    struct Node *next;
} node;

int n, m;

node *create(int id)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}
void push_back(node *phead, int id)
{
    node *newNode = create(id);
    if (phead->next == NULL)
    {
        phead->next = newNode;
    }
    else
    {
        node *tail = phead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}
int cir_out(node *phead)
{
    node *cur = phead;
    int i = 0;
    while (cur != cur->next)
    {
        // 遍历到第m-1个

        for (i = 0; i < m - 1; i++)
        {
            cur = cur->next;
        }
        node *temp = cur->next;
        cur->next = temp->next;
        free(temp);
        cur = cur->next;
    }
    int last_Id = cur->id;
    return last_Id;
}
int main()
{
    // 头结点之前的前置节点
    node *head = create(0);
    printf("请输入同学数量n: \n");
    scanf("%d", &n);
    printf("请输入报到数m: \n");
    scanf("%d", &m);
    int i;
    for (i = 1; i <= n; i++)
    {
        push_back(head, i);
    }
    // 得到循环链表
    node *cur = head->next;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = head->next;
    // 循环淘汰

    printf("最后剩下的是同学编号: %d\n", cir_out(head->next));
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int id;
    struct Node *next;
} node;

int n, m;

node *create(int id)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}
void push_back(node *phead, int id)
{
    node *newNode = create(id);
    if (phead->next == NULL)
    {
        phead->next = newNode;
    }
    else
    {
        node *tail = phead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}
int cir_out(node *phead)
{
    node *cur = phead;
    int i = 0;
    while (cur != cur->next)
    {
        // 遍历到第m-1个

        for (i = 0; i < m - 1; i++)
        {
            cur = cur->next;
        }
        node *temp = cur->next;
        cur->next = temp->next;
        free(temp);
        cur = cur->next;
    }
    int last_Id = cur->id;
    return last_Id;
}
int main()
{
    // 头结点之前的前置节点
    node *head = create(0);
    printf("请输入同学数量n: \n");
    scanf("%d", &n);
    printf("请输入报到数m: \n");
    scanf("%d", &m);
    int i;
    for (i = 1; i <= n; i++)
    {
        push_back(head, i);
    }
    // 得到循环链表
    node *cur = head->next;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = head->next;
    // 循环淘汰

    printf("最后剩下的是同学编号: %d\n", cir_out(head->next));
    return 0;
}
>>>>>>> 6319aa0c07bd657e7ed639217d155fb1b315f651
