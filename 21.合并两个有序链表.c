// ��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL || list2 == NULL)
    {
        if (list1 == NULL && list2 != NULL)
        {
            return list2;
        }
        else if (list1 != NULL && list2 == NULL)
        {
            return list1;
        }
        else
        {
            return NULL;
        }
    }
    struct ListNode *head = NULL;
    if (list1->val <= list2->val)
    {
        head = list1;
        list1 = list1->next;
        head->next = NULL;
    }
    else
    {
        head = list2;
        list2 = list2->next;
        head->next = NULL;
    }
    struct ListNode *tail = head;
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
            tail->next = NULL;
        }
        else
        {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
            tail->next = NULL;
        }
    }
    if (list1 == NULL)
    {
        tail->next = list2;
    }
    else
    {
        tail->next = list1;
    }
    return head;
}