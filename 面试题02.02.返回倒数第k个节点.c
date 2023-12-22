// 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
int kthToLast(struct ListNode *head, int k)
{
    struct ListNode *left = head, *right = head;
    while (k--)
    {
        right = right->next;
    }
    while (right)
    {
        right = right->next;
        left = left->next;
    }
    return left->val;
}
