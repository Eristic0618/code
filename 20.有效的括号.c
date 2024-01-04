//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
//��Ч�ַ��������㣺
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef char STDataType;

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

bool isValid(char *s)
{
    Stack st;
    StackInit(&st);
    while (*s)
    {
        if (*s == '(' || *s == '[' || *s == '{')
        {
            StackPush(&st, *s);
        }
        else
        {
            if (StackEmpty(&st))
                return false;
            if ((*s == ')' && StackTop(&st) != '(') || (*s == ']' && StackTop(&st) != '[') || (*s == '}' && StackTop(&st) != '{'))
            {
                return false;
            }
            else
            {
                StackPop(&st);
            }
        }
        s++;
    }
    bool ret = StackEmpty(&st);
    StackDestory(&st);
    return ret;
}