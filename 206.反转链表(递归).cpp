// https://leetcode.cn/problems/reverse-linked-list/description/
// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
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