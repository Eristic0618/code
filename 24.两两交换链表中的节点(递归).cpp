// https://leetcode.cn/problems/swap-nodes-in-pairs/description/
// ����һ���������������������ڵĽڵ㣬�����ؽ����������ͷ�ڵ㡣������ڲ��޸Ľڵ��ڲ���ֵ���������ɱ��⣨����ֻ�ܽ��нڵ㽻������
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *tmp = head->next;
        if (tmp == nullptr)
            return head;
        head->next = swapPairs(tmp->next);
        tmp->next = head;
        return tmp;
    }
};