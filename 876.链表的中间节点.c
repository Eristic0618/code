// ���㵥�����ͷ��� head �������ҳ�������������м��㡣
// ����������м��㣬�򷵻صڶ����м���
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