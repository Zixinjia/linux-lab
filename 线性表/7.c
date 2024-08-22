// 逆置双链表
void reverseDoublyLinkedList(DListNode **head)
{
    if (head == NULL || *head == NULL || (*head)->next == NULL)
    {
        return;
    }

    DListNode *prev = NULL;
    DListNode *curr = (*head)->next;
    DListNode *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;

        curr->next = prev;
        curr->prev = next;

        prev = curr;
        curr = next;
    }

    (*head)->next = prev;

    if (prev != NULL)
    {
        prev->prev = NULL;
    }
}
