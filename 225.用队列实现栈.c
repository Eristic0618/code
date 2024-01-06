typedef int QDataType;

typedef struct QueueNode
{
    struct QueueNode *next;
    QDataType data;
} QNode;

typedef struct Queue
{
    QNode *phead; // ָ���ͷ
    QNode *ptail; // ָ���β
    int size;     // ��ѡ�����Ч��
} Queue;

// ���е���ɾ��Ľӿ�ʵ�֣���Ϊָ���ڽṹ�������Բ���Ҫ������ָ�룩

void QueueInit(Queue *que); // ��ʼ������

void QueueDestroy(Queue *que); // ���ٶ���

void QueuePush(Queue *que, QDataType x); // ��β�����

void QueuePop(Queue *que); // ��ͷ������

QDataType QueueFront(Queue *que); // ��ȡ����ͷ��Ԫ��

QDataType QueueBack(Queue *que); // ��ȡ���ж�βԪ��

int QueueSize(Queue *que); // ��ȡ��������ЧԪ�ظ���

bool QueueEmpty(Queue *que); // �������Ƿ�Ϊ��

void QueueInit(Queue *que) // ��ʼ������
{
    assert(que);
    que->phead = NULL;
    que->ptail = NULL;
    que->size = 0;
}

void QueueDestroy(Queue *que) // ���ٶ���
{
    assert(que);
    QNode *cur = que->phead;
    while (cur)
    {
        que->phead = que->phead->next;
        free(cur);
        cur = que->phead;
    }
    que->phead = que->ptail = NULL;
    que->size = 0;
}

void QueuePush(Queue *que, QDataType x) // ��β�����
{
    assert(que);
    QNode *newnode = (QNode *)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;
    if (que->phead == NULL || que->ptail == NULL)
    {
        assert(que->phead == NULL);
        assert(que->ptail == NULL);
        que->phead = que->ptail = newnode;
    }
    else
    {
        que->ptail->next = newnode;
        que->ptail = newnode;
    }
    que->size++;
}

void QueuePop(Queue *que) // ��ͷ������
{
    assert(que);
    assert(!QueueEmpty(que));
    if (que->phead->next == NULL)
    {
        free(que->phead);
        que->phead = que->ptail = NULL;
    }
    else
    {
        QNode *cur = que->phead;
        que->phead = que->phead->next;
        free(cur);
    }
    que->size--;
}

QDataType QueueFront(Queue *que) // ��ȡ����ͷ��Ԫ��
{
    assert(que);
    assert(!QueueEmpty(que));
    return que->phead->data;
}

QDataType QueueBack(Queue *que) // ��ȡ���ж�βԪ��
{
    assert(que);
    assert(!QueueEmpty(que));
    return que->ptail->data;
}

int QueueSize(Queue *que) // ��ȡ��������ЧԪ�ظ���
{
    assert(que);
    return que->size;
}

bool QueueEmpty(Queue *que) // �������Ƿ�Ϊ��
{
    assert(que);
    return que->size == 0;
}

typedef struct
{
    Queue q1;
    Queue q2;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    if (obj == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    QueueInit(&obj->q1);
    QueueInit(&obj->q2);
    return obj;
}

void myStackPush(MyStack *obj, int x)
{
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

int myStackPop(MyStack *obj)
{
    Queue *Emptyque = &obj->q1;
    Queue *NonEmptyque = &obj->q2;
    if (!QueueEmpty(&obj->q1))
    {
        Emptyque = &obj->q2;
        NonEmptyque = &obj->q1;
    }
    while (NonEmptyque->size > 1)
    {
        QueuePush(Emptyque, QueueFront(NonEmptyque));
        QueuePop(NonEmptyque);
    }
    int top = QueueFront(NonEmptyque);
    QueuePop(NonEmptyque);
    return top;
}

int myStackTop(MyStack *obj)
{
    if (!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack *obj)
{
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack *obj)
{
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}