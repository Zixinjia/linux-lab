//编写算法 int CountList(LinkNode L,ElemType x)，
//实现在给定的带头结点的单链表 L 中，计算数据域为 x的结点的个数。
int CountList(LinkNode L, ElemType x)
{
    if (L == NULL)
        return 0;
    int ans = 0;
    while (L != NULL)
    {
        if (L->data == x)
            ans++;
        L = L->next;
    }
    return ans;
}
