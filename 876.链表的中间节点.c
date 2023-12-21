// 给你单链表的头结点 head ，请你找出并返回链表的中间结点。
// 如果有两个中间结点，则返回第二个中间结点
struct ListNode *middleNode(struct ListNode *head)
{
    struct ListNode *left = head, *right = head;
    while (right->next)
    {
        if (right->next->next != NULL)
        {
            right = right->next->next;
            left = left->next;
        }
        else
        {
            right = right->next;
            left = left->next;
        }
    }
    return left;
}