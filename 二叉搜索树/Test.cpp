#include "Key_value.h"

//int main()
//{
//	BSTree<string, string> dict;
//	dict.insert("sort", "ÅÅÐò");
//	dict.insert("left", "×ó");
//	dict.insert("right", "ÓÒ");
//	dict.insert("insert", "²åÈë");
//	dict.insert("key", "¹Ø¼ü×Ö");
//
//	string str;
//	while (cin >> str)
//	{
//		BSTreeNode<string, string>* ret = dict.find(str);
//		if (ret)
//			cout << ret->_val << endl;
//		else
//			cout << "NOFIND" << endl;
//	}
//	return 0;
//}

int main()
{
	string a[] = { "Æ»¹û","Î÷¹Ï","Æ»¹û" ,"Æ»¹û" ,"Æ»¹û","Î÷¹Ï", "Æ»¹û" };
	BSTree<string, int> count;
	for (auto i : a)
	{
		BSTreeNode<string, int>* ret = count.find(i);
		if (ret == nullptr)
			count.insert(i, 1);
		else
			ret->_val++;
	}
	count.InOrder();
	return 0;
}
