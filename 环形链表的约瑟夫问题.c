// ���Ϊ 1 �� n �� n ����Χ��һȦ���ӱ��Ϊ 1 ���˿�ʼ���������� m �����뿪��
// ��һ���˼����� 1 ��ʼ������
// n-1 �ֽ����Ժ�ֻʣ��һ���ˣ���������µ�����˱���Ƕ��٣�
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param n int����
 * @param m int����
 * @return int����
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode *CreateList(int n)
{
    int i = 1;
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;
    struct ListNode *tail = head;
    i = 2;
    while (i <= n)
    {
        struct ListNode *newnode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newnode->val = i;
        newnode->next = NULL;
        tail->next = newnode;
        tail = tail->next;
        i++;
    }
    tail->next = head;
    return head;
}

int ysf(int n, int m)
{
    if (n == 1)
        return n;
    struct ListNode *plist = CreateList(n);
    while (plist->next != plist)
    {
        struct ListNode *prev = plist;
        struct ListNode *cur = plist;
        for (int i = 1; i < m - 1; i++)
        {
            prev = prev->next;
        }
        for (int i = 1; i < m; i++)
        {
            cur = cur->next;
        }
        plist = cur->next;
        prev->next = plist;
        free(cur);
        cur = NULL;
    }
    return plist->val;
}