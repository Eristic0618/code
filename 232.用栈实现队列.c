typedef int STDataType;

typedef struct Stack
{
    STDataType *arr;
    int top;      // 栈顶
    int capacity; // 容量
} Stack;

void StackInit(Stack *pst); // 初始化栈

void StackPush(Stack *pst, STDataType x); // 入栈

void StackPop(Stack *pst); // 出栈

STDataType StackTop(Stack *pst); // 获取栈顶元素

int StackSize(Stack *pst); // 获取栈中有效元素个数

bool StackEmpty(Stack *pst); // 检测栈是否为空

void StackDestory(Stack *pst); // 销毁栈

void StackInit(Stack *pst) // 初始化栈
{
    assert(pst);
    pst->arr = NULL;
    pst->top = 0; // top指向栈顶数据的下一个位置
    pst->capacity = 0;
}

void StackPush(Stack *pst, STDataType x) // 入栈
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

void StackPop(Stack *pst) // 出栈
{
    assert(pst);
    assert(!StackEmpty(pst));
    pst->top--;
}

STDataType StackTop(Stack *pst) // 获取栈顶元素
{
    assert(pst);
    assert(!StackEmpty(pst));
    return pst->arr[pst->top - 1];
}

int StackSize(Stack *pst) // 获取栈中有效元素个数
{
    assert(pst);
    return pst->top;
}

bool StackEmpty(Stack *pst) // 检测栈是否为空
{
    assert(pst);
    return pst->top == 0;
}

void StackDestory(Stack *pst) // 销毁栈
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