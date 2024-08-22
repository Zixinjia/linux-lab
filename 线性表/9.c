bool isSymmetric(LinkedList *list)
{
    if (list == NULL || list->head == NULL || list->head->next == list->head)
    {
        return true;
    }
    Node *left = list->head->next;
    Node *right = list->head->prev;
    while (left != right && left->prev != right)
    {
        if (left->data != right->data)
        {
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    return true;
}