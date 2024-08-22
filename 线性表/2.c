//编写算法 bool InsertList(LinkLNode L,ElemType a,ElemType x)，
// 实现在一个带头结点的单链表 L 中，向数据域为 a 的结点后插入数据域为 x的节点
bool iNSERTlIST(LinkLNode L, ElemType a, ElemType x)
{
    if (L == NULL)
        return false;
    while (L != NULL)
    {
        if (L->next != NULL && L->next->data == a)
        {
            LinkLNode newNode = createNode(x);
            newNode->next = L->next;
            L->next = newNode;
        }
        L = L->next;
    }
    return true;
}