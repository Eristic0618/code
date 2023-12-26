// ����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
class Partition
{
public:
    ListNode *partition(ListNode *pHead, int x)
    {
        struct ListNode *lesshead, *lesstail, *greaterhead, *greatertail;
        lesshead = lesstail = (struct ListNode *)malloc(sizeof(struct ListNode));
        greaterhead = greatertail = (struct ListNode *)malloc(sizeof(struct ListNode));
        struct ListNode *cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                lesstail->next = cur;
                lesstail = cur;
                cur = cur->next;
            }
            else
            {
                greatertail->next = cur;
                greatertail = cur;
                cur = cur->next;
            }
        }
        lesstail->next = greaterhead->next;
        greatertail->next = NULL;
        pHead = lesshead->next;
        free(lesshead);
        free(greaterhead);
        return pHead;
    }
};