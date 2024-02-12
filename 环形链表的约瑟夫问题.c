// 编号为 1 到 n 的 n 个人围成一圈。从编号为 1 的人开始报数，报到 m 的人离开。
// 下一个人继续从 1 开始报数。
// n-1 轮结束以后，只剩下一个人，问最后留下的这个人编号是多少？
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param n int整型
 * @param m int整型
 * @return int整型
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