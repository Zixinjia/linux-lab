/*
已知单链表 L 是一个非空递减有序表，编写算法实现将值为 x 的结点插入 L 中并保持 L
仍然有序。
*/
bool insertNode(LinkLNode L, int x)
{
    if (L == NULL)
        return false;
    int cur = 0;
    while (L != NULL)
    {
        cur = L->data;
        if (cur >= x)
        {
            LinkLNode newNode = createNode(x);
            //如果要插入节点在最后
            if (L->next == NULL)
            {
                L->next = newNode;
            }
            else
            {
                newNode->next = L->next;
                L->next = newNode;
            }
        }
    }
    return true;
}