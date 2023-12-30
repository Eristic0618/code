// ����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣
// ������������ ����� ���Ӧ�������� n �� ȫ�� �ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ��
// �½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬��
// ���������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��
// ���ظ��������ͷ�ڵ�
struct Node *copyRandomList(struct Node *head)
{
    struct Node *cur = head;
    while (cur)
    {
        struct Node *copy = (struct Node *)malloc(sizeof(struct Node));
        copy->val = cur->val;
        struct Node *next = cur->next;
        cur->next = copy;
        copy->next = next;
        cur = next;
    }
    cur = head;
    while (cur)
    {
        struct Node *copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    struct Node *copyhead = NULL;
    struct Node *copytail = NULL;
    cur = head;
    while (cur)
    {
        struct Node *copy = cur->next;
        struct Node *next = copy->next;
        if (copytail == NULL)
        {
            copytail = copyhead = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copytail->next;
        }
        cur->next = next;
        cur = next;
    }
    return copyhead;
}