/**
 * 已知一个带头结点的单链表，编写一个算法实现从单链表中删除自第 i 个结点起的 n 的
 * 结点。（假设该单链表结点个数大于 i+n）
 */
bool deleteNode(LinkLNode L, int i, int n)
{
    if (L == NULL)
        return false;
    int cnt1 = 0, cnt2 = 0;
    LinkLNode cur1 = L;
    LinkLNode cur2 = L;
    //先用指针找到第i个节点
    while (cnt1 != i)
    {
        cur1 = cur1->next;
        cnt1++;
    }
    //再用指针找到第i+n个节点
    while (cnt2 != i + n)
    {
        cur2 = cur2->next;
        cnt2++;
    }
    cur1->next = cur2;
    return true;
}