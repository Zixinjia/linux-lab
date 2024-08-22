//设计一个算法，删除一个单链表 L 中元素值最大的结点（假设这样的结点唯一）。

//也可以用pre记录前一个 ,cur双指针，就不需要第二个遍历整个链表了
bool deleteMaxNode(LinkLNode L)
{
    if (L == NULL)
        return false;
    int mx = -1e6;
    LinkLNode cur = NULL;
    LinkLNode head = L;
    //找到最大值
    while (L != NULL)
    {
        if (L->data > mx)
        {
            mx = L->data;
            cur = L;
        }
        L = L->next;
    }
    while (head != NULL)
    {
        if (head->next == cur)
        {
            //如果此节点是最后一个
            head->next = head->next->next;
        }
    }
    return true;
}

//有一个带头结点的双链表 L（至少有一个数据结点），设计一个算法使其元素递增有序排

void sortDoublyLinkedList(DListNode *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return;
    }

    DListNode *sortedTail = head->next;
    DListNode *curr = sortedTail->next;

    // 从第二个节点开始遍历链表
    while (curr != NULL)
    {
        DListNode *nextNode = curr->next;
        DListNode *prev = NULL;

        if (curr->data < sortedTail->data)
        {
            curr->next = sortedTail;
            sortedTail->prev = curr;
            if (head->next == sortedTail)
            {
                head->next = curr;
            }
            sortedTail = curr;
            sortedTail->prev = prev;
        }
        else
        {

            prev = sortedTail;
            while (prev->next != NULL && prev->next->data < curr->data)
            {
                prev = prev->next;
            }
            curr->next = prev->next;
            if (prev->next != NULL)
            {
                prev->next->prev = curr;
            }
            prev->next = curr;
            curr->prev = prev;
        }

        curr = nextNode;
    }
}
