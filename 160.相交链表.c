// ���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int la = 1, lb = 1, diff = 0;
    struct ListNode *tailA = headA, *tailB = headB;
    while (tailA->next)
    {
        tailA = tailA->next;
        la++;
    }
    while (tailB->next)
    {
        tailB = tailB->next;
        lb++;
    }
    tailA = headA;
    tailB = headB;
    if (la >= lb)
    {
        diff = la - lb;
        while (diff--)
        {
            tailA = tailA->next;
        }
    }
    else
    {
        diff = lb - la;
        while (diff--)
        {
            tailB = tailB->next;
        }
    }
    while (tailA)
    {
        if (tailA == tailB)
        {
            return tailA;
        }
        tailA = tailA->next;
        tailB = tailB->next;
    }
    return NULL;
}