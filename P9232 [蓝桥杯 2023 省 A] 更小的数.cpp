// https://www.luogu.com.cn/problem/P9232
#include <bits/stdc++.h>
using namespace std;
//1.ѡ����ִ�������߽�����ұ߽磬��ת��õ���������С�ھ����֣��Ϸ�
//  ����߽�С���ұ߽���ת��õ��������ִ��ھ����֣����Ϸ�
//  ����߽�����ұ߽磬�����Ҹ���Сһ�񣬼����ж�
//2.���������������ִ�
//	���������ִ���ʱ�临�Ӷ�ΪO(N^2)
//	��������ÿһλ����ȣ����ʱ�临�Ӷ�ΪO(N^3)����Ϊ��ʱ��Ҫ���ϵ���С��Χ
//3.�Ż�������dp���ɽ�ʱ�临�Ӷ�ѹ��ΪO(N^2)
//	����dpʡȥ����С��Χ�Ĳ�����ֻ��Ҫ���[i+1][j-1]��Χ�Ƿ�Ϸ�����

int main()
{
	char str[5010];
	vector<vector<int>> dp(5010, vector<int>(5010));
	scanf("%s", str);
	int n = strlen(str), ret = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (str[i] > str[i + 1])
			dp[i][i + 1] = 1;
	}
	for (int len = 3; len <= n; len++)
	{
		for (int i = 0; i <= n - len; i++)
		{
			int right = i + len - 1;
			if (str[i] == str[right])
				dp[i][right] = dp[i + 1][right - 1];
			else if (str[i] > str[right])
				dp[i][right] = 1;
			else
				dp[i][right] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] == 1)
				ret++;
		}
	}
	printf("%d", ret);
	return 0;
}