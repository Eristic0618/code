#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "RBTree.h"
#include "Mymap.h"
#include "Myset.h"

//int main()
//{
//	//int a[] = { 4,2,6,1,3,5,15,7,16,14 };
//	//int a[] = { 16,3,7,11,9,26,18,14,15 };
//	//int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	const int N = 1000000;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//
//	for (int i = 0; i < N; i++)
//	{
//		v.push_back(rand() + i);
//	}
//
//	RBTree<int, int> t;
//	for (auto i : v)
//	{
//		t.insert(make_pair(i, 1));
//	}
//	//t.InOrder();
//	cout << t.Height() << endl;
//	cout << t.Size() << endl;
//	if (t.IsBalance())
//		cout << "是红黑树" << endl;
//	return 0;
//}

void test_map()
{
	string a[] = { "苹果","西瓜","苹果" ,"苹果" ,"苹果","西瓜", "苹果" };
	Eristic::map<string, int> count;
	for (auto& i : a)
	{
		count[i]++;
	}
	for (auto i : count)
	{
		cout << i.first << ":" << i.second << endl;
	}
	cout << endl;
}

void test_set()
{
	Eristic::set<int> s;
	s.insert(7);
	s.insert(2);
	s.insert(4);
	s.insert(4);
	s.insert(8);
	s.insert(1);
	s.insert(17);
	s.insert(10);
	
	Eristic::set<int>::iterator it = s.begin();

	for (auto i : s)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	//test_map();
	test_set();
	return 0;
}