#include "AVLTree.h"
#include <vector>

//int main()
//{
//	//int a[] = { 4,2,6,1,3,5,15,7,16,14 };
//	//int a[] = { 16,3,7,11,9,26,18,14,15 };
//	//int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//const int N = 1000000;
//	//vector<int> v;
//	//v.reserve(N);
//	//srand(time(0));
//
//	//for (int i = 0; i < N; i++)
//	//{
//	//	v.push_back(rand() + i);
//	//}
//
//	//AVLTree<int, int> t;
//
//	//size_t begin1 = clock();
//	//for (auto i : v)
//	//{
//	//	t.insert(make_pair(i, 1));
//	//}
//	//size_t end1 = clock();
//	//cout << "insert:" << end1 - begin1 << endl;
//
//	//size_t begin2 = clock();
//	//for (auto i : v)
//	//{
//	//	t.Find(i);
//	//}
//	//size_t end2 = clock();
//	//cout << "Find:" << end2 - begin2 << endl;
//
//	////t.InOrder();
//	//cout << t.Height() << endl;
//	//cout << t.Size() << endl;
//	//if (t.IsBalance())
//	//	cout << "是AVL树" << endl;
//	//else
//	//	cout << "不是AVL树" << endl;
//	return 0;
//}

int main()
{
	const int N = 1000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (int i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
	}

	AVLTree<int, int> t;
	for (auto i : v)
	{
		t.insert(make_pair(i, 1));
	}
	t.InOrder();
	if (t.IsBalance())
		cout << "是AVL树" << endl;
	else
		cout << "不是AVL树" << endl;
	return 0;
}