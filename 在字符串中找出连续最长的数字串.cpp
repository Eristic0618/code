//现有一个字符串str，输出字符串str中的最长的数字子串:
//输入描述
//一个包含字母和数字的字符串，长度不超过255.
//保证最少有一个字符是数字，且只有一个最长的数字子串。
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
