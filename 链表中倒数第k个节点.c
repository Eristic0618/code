// 输入一个链表，输出该链表中倒数第k个结点。
struct ListNode *FindKthToTail(struct ListNode *pListHead, int k)
{
    struct ListNode *fast = pListHead;
    struct ListNode *slow = pListHead;
    while (k--)
    {
        if (fast == NULL)
            return NULL;
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}