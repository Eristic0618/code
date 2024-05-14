// https://leetcode.cn/problems/swap-nodes-in-pairs/description/
// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
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