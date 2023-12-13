#include "SeqList.c"

int main()
{
    SeqList sl;
    SeqListInit(&sl);
    SeqListPushBack(&sl, 1);
    SeqListPushBack(&sl, 2);
    SeqListPushBack(&sl, 3);
    SeqListPushBack(&sl, 4);
    SeqListPrint(&sl);

    SeqListPopBack(&sl);
    SeqListPopBack(&sl);
    SeqListPrint(&sl);

    SeqListPushFront(&sl, 2);
    SeqListPushFront(&sl, 3);
    SeqListPushFront(&sl, 5);
    SeqListPrint(&sl);
    
    SeqListPopFront(&sl);
    SeqListPrint(&sl);

    SeqListInsert(&sl, 2, 7);
    SeqListPrint(&sl);

    SeqListErase(&sl, 2);
    SeqListPrint(&sl);

    SeqListDestory(&sl);
    return 0;
}