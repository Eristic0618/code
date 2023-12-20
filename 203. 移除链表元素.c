// ����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
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