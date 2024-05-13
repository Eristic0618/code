// https://leetcode.cn/problems/reverse-linked-list/description/
// ���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};