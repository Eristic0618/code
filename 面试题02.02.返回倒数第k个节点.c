// ʵ��һ���㷨���ҳ����������е����� k ���ڵ㡣���ظýڵ��ֵ��
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
