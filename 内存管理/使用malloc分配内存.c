#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *nodePtr = (struct Node *)malloc(sizeof(struct Node));
    if (nodePtr == NULL)
    {
        printf("内存分配失败\n");
        return 1;
    }
    nodePtr->data = 10;
    nodePtr->next = NULL;
    printf("数据: %d\n", nodePtr->data);
    printf("指针: %p\n", nodePtr->next);
    free(nodePtr);

    return 0;
}