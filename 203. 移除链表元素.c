// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *prev = NULL, *cur = head;
    while (cur)
    {
        if (cur->val == val)
        {
            if (prev == NULL)
            {
                cur = head->next;
                free(head);
                head = cur;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}