typedef int STDataType;

typedef struct Stack
{
    STDataType *arr;
    int top;      // ջ��
    int capacity; // ����
} Stack;

void StackInit(Stack *pst); // ��ʼ��ջ

void StackPush(Stack *pst, STDataType x); // ��ջ

void StackPop(Stack *pst); // ��ջ

STDataType StackTop(Stack *pst); // ��ȡջ��Ԫ��

int StackSize(Stack *pst); // ��ȡջ����ЧԪ�ظ���

bool StackEmpty(Stack *pst); // ���ջ�Ƿ�Ϊ��

void StackDestory(Stack *pst); // ����ջ

void StackInit(Stack *pst) // ��ʼ��ջ
{
    assert(pst);
    pst->arr = NULL;
    pst->top = 0; // topָ��ջ�����ݵ���һ��λ��
    pst->capacity = 0;
}

void StackPush(Stack *pst, STDataType x) // ��ջ
{
    if (pst->top == pst->capacity)
    {
        int NewCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
        STDataType *cmp = (STDataType *)realloc(pst->arr, NewCapacity * sizeof(STDataType));
        if (cmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        pst->arr = cmp;
        pst->capacity = NewCapacity;
    }
    pst->arr[pst->top] = x;
    pst->top++;
}

void StackPop(Stack *pst) // ��ջ
{
    assert(pst);
    assert(!StackEmpty(pst));
    pst->top--;
}

STDataType StackTop(Stack *pst) // ��ȡջ��Ԫ��
{
    assert(pst);
    assert(!StackEmpty(pst));
    return pst->arr[pst->top - 1];
}

int StackSize(Stack *pst) // ��ȡջ����ЧԪ�ظ���
{
    assert(pst);
    return pst->top;
}

bool StackEmpty(Stack *pst) // ���ջ�Ƿ�Ϊ��
{
    assert(pst);
    return pst->top == 0;
}

void StackDestory(Stack *pst) // ����ջ
{
    free(pst->arr);
    pst->arr = NULL;
    pst->top = pst->capacity = 0;
}

typedef struct
{
    Stack pushstack;
    Stack popstack;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
    if (obj == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    StackInit(&obj->pushstack);
    StackInit(&obj->popstack);
    return obj;
}

void myQueuePush(MyQueue *obj, int x)
{
    StackPush(&obj->pushstack, x);
}

int myQueuePop(MyQueue *obj)
{
    // if(!StackEmpty(&obj->popstack))
    // {
    //     int front = StackTop(&obj->popstack);
    //     StackPop(&obj->popstack);
    //     return front;
    // }
    // else
    // {
    //     while(!StackEmpty(&obj->pushstack))
    //     {
    //         StackPush(&obj->popstack , StackTop(&obj->pushstack));
    //         StackPop(&obj->pushstack);
    //     }
    //     int front = StackTop(&obj->popstack);
    //     StackPop(&obj->popstack);
    //     return front;
    // }
    int front = myQueuePeek(obj);
    StackPop(&obj->popstack);
    return front;
}

int myQueuePeek(MyQueue *obj)
{
    if (!StackEmpty(&obj->popstack))
    {
        return StackTop(&obj->popstack);
    }
    else
    {
        while (!StackEmpty(&obj->pushstack))
        {
            StackPush(&obj->popstack, StackTop(&obj->pushstack));
            StackPop(&obj->pushstack);
        }
        return StackTop(&obj->popstack);
    }
}

bool myQueueEmpty(MyQueue *obj)
{
    return StackEmpty(&obj->pushstack) && StackEmpty(&obj->popstack);
}

void myQueueFree(MyQueue *obj)
{
    StackDestory(&obj->pushstack);
    StackDestory(&obj->popstack);
    free(obj);
}