// ���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������

// struct ListNode* reverseList(struct ListNode* head) {
//     struct ListNode* n1 =NULL,*n2=head,*n3=NULL;
//     if(n2!=NULL)
//         n3=head->next;
//     while(n2)
//     {
//         n2->next=n1;
//         n1=n2;
//         n2=n3;
//         if(n3!=NULL)
//             n3=n3->next;
//     }
//     return n1;
// }

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *cur = head;
    struct ListNode *rehead = NULL;
    while (cur)
    {
        struct ListNode *next = cur->next;
        cur->next = rehead;
        rehead = cur;
        cur = next;
    }
    return rehead;
}