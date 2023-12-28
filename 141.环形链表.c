// ����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
// �����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ���
// ��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
bool hasCycle(struct ListNode *head)
{
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}