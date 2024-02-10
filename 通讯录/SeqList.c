#include "SeqList.h"

void SeqListDestory(SeqList* psl)
{
    assert(psl);
    free(psl->a);
    psl->a = NULL;
    psl->capicity = 0;
    psl->size = 0;
}

void SeqListInit(SeqList* psl)
{
    assert(psl);
    psl->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
    if (psl->a == NULL)
    {
        perror("malloc fail");
        return;
    }
    psl->size = 0;
    psl->capicity = 4;
}

void CheckCapacity(SeqList* psl)
{
    assert(psl);
    if (psl->size == psl->capicity)
    {
        SLDataType* tmp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * psl->capicity * 2);
        if (tmp == NULL)
        {
            perror("realloc fail");
            return;
        }
        psl->a = tmp;
        psl->capicity *= 2;
    }
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
    assert(psl);
    CheckCapacity(psl);
    psl->a[psl->size++] = x;
}

void SeqListErase(SeqList* psl, size_t pos)
{
    assert(psl);
    assert(0 <= pos && pos < psl->size);
    while (pos < psl->size - 1)
    {
        psl->a[pos] = psl->a[pos + 1];
        pos++;
    }
    psl->size--;
}
