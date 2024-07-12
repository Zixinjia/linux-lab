#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int ci;
    char ei[10];
    struct Node *next;
} node;

void print(node *phead)
{
    node *cur = phead;
    while (cur != NULL)
    {
        printf("%d %s\n", cur->ci, cur->ei);
        cur = cur->next;
    }
    printf("\n");
}

node *create_node(int x1, char x2[10])
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->ci = x1;
    strcpy(newNode->ei, x2);
    newNode->next = NULL;
    return newNode;
}

void push_back(node **pphead, int x1, char x2[10])
{
    node *newNode = create_node(x1, x2);
    if (*pphead == NULL)
    {
        *pphead = newNode;
    }
    else
    {
        node *tail = *pphead;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

node *add(node *phead1, node *phead2)
{
    node *head = create_node(0, " ");
    node *current = head;
    // 75 1 30 x 95 x8 50 x9
    // 80 x 25 x7 90 x8

    // 75 110x
    while (phead1 && phead2)
    {
        if (strcmp(phead1->ei, phead2->ei) == 0)
        {
            int sum = phead1->ci + phead2->ci;
            if (sum != 0)
            {
                current->next = create_node(sum, phead1->ei);
                current = current->next;
            }
            phead1 = phead1->next;
            phead2 = phead2->next;
        }
        else if (strcmp(phead1->ei, phead2->ei) < 0)
        {
            current->next = create_node(phead1->ci, phead1->ei);
            current = current->next;
            phead1 = phead1->next;
        }
        else
        {
            current->next = create_node(phead2->ci, phead2->ei);
            current = current->next;
            phead2 = phead2->next;
        }
    }

    while (phead1)
    {
        current->next = create_node(phead1->ci, phead1->ei);
        current = current->next;
        phead1 = phead1->next;
    }
    while (phead2)
    {
        current->next = create_node(phead2->ci, phead2->ei);
        current = current->next;
        phead2 = phead2->next;
    }

    return head->next;
}

int main()
{
    int m, k;
    scanf("%d", &m);
    node *phead1 = create_node(0, " ");
    node *phead2 = create_node(0, " ");
    int i;
    for (i = 0; i < m; i++)
    {
        int ci;
        char ei[10];
        scanf("%d %s", &ci, ei);
        push_back(&phead1, ci, ei);
    }

    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        int ci;
        char ei[10];
        scanf("%d %s", &ci, ei);
        push_back(&phead2, ci, ei);
    }
    node *result = add(phead1->next, phead2->next);
    print(result);

    return 0;
}
// 4
// 75 1
// 30 x
// 95 x8
// 50 x9
// 3
// 80 x
// 25 x7
// 90 x8
