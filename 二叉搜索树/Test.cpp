#include "Key_value.h"

//int main()
//{
//	BSTree<string, string> dict;
//	dict.insert("sort", "����");
//	dict.insert("left", "��");
//	dict.insert("right", "��");
//	dict.insert("insert", "����");
//	dict.insert("key", "�ؼ���");
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
	string a[] = { "ƻ��","����","ƻ��" ,"ƻ��" ,"ƻ��","����", "ƻ��" };
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
