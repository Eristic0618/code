//����һ���ַ���str������ַ���str�е���������Ӵ�:
//��������
//һ��������ĸ�����ֵ��ַ��������Ȳ�����255.
//��֤������һ���ַ������֣���ֻ��һ����������Ӵ���
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int l = 0;
	int r = 0;
	int maxl = 0, maxr = 0;
	int flag = 0;
	while (r < str.size())
	{
		while (isdigit(str[l]) && isdigit(str[r]) && !flag)
		{
			maxl = l;
			r++;
			maxr = r;
		}
		if (isalpha(str[r]))
			flag++;
		if (isalpha(str[l]))
			flag--;
		l++;
		r++;
	}
	for (int i = maxl; i < maxr; i++)
	{
		cout << str[i];
	}
	return 0;
}
