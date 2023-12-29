// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct ListNode *meet = slow;
            while (head != meet)
            {
                head = head->next;
                meet = meet->next;
            }
            return head;
        }
    }
    return NULL;
}