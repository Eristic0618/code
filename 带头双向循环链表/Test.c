#include "DCList.h"

void test1()
{
	ListNode* plist = ListCreate();
	DLTPushBack(plist, 1);
	DLTPushBack(plist, 2);
	DLTPushBack(plist, 3);
	DLTPushBack(plist, 4);
	ListNode* pos = DListFind(plist, 3);
	DListErase(pos);
	DListPrint(plist);
	DListDestory(plist);
	plist = NULL;
}

void test2()
{
	ListNode* plist = ListCreate();
	DLTPopFront(plist);
	DLTPopBack(plist);
	DListPrint(plist);
}

int main()
{
	test1();
	return 0;
}