typedef int QDataType;

typedef struct QueueNode
{
    struct QueueNode *next;
    QDataType data;
} QNode;

typedef struct Queue
{
    QNode *phead; // 指向队头
    QNode *ptail; // 指向队尾
    int size;     // 可选，提高效率
} Queue;

// 队列的增删查改接口实现（因为指针在结构体中所以不需要传二级指针）

void QueueInit(Queue *que); // 初始化队列

void QueueDestroy(Queue *que); // 销毁队列

void QueuePush(Queue *que, QDataType x); // 队尾入队列

void QueuePop(Queue *que); // 队头出队列

QDataType QueueFront(Queue *que); // 获取队列头部元素

QDataType QueueBack(Queue *que); // 获取队列队尾元素

int QueueSize(Queue *que); // 获取队列中有效元素个数

bool QueueEmpty(Queue *que); // 检测队列是否为空

void QueueInit(Queue *que) // 初始化队列
{
    assert(que);
    que->phead = NULL;
    que->ptail = NULL;
    que->size = 0;
}

void QueueDestroy(Queue *que) // 销毁队列
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

void QueuePush(Queue *que, QDataType x) // 队尾入队列
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

void QueuePop(Queue *que) // 队头出队列
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

QDataType QueueFront(Queue *que) // 获取队列头部元素
{
    assert(que);
    assert(!QueueEmpty(que));
    return que->phead->data;
}

QDataType QueueBack(Queue *que) // 获取队列队尾元素
{
    assert(que);
    assert(!QueueEmpty(que));
    return que->ptail->data;
}

int QueueSize(Queue *que) // 获取队列中有效元素个数
{
    assert(que);
    return que->size;
}

bool QueueEmpty(Queue *que) // 检测队列是否为空
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