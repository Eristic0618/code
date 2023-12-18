#include "SList.h"

void test1()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTNode* pos = SLTFind(plist, 2);
	SLTEraseAfter(pos);
	SLTPrint(plist);
}

int main()
{
	test1();
	return 0;
}
