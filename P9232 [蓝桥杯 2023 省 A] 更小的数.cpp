// https://www.luogu.com.cn/problem/P9232
#include <bits/stdc++.h>
using namespace std;
//1.选择的字串，若左边界大于右边界，则反转后得到的新数字小于旧数字，合法
//  若左边界小于右边界则反转后得到的新数字大于旧数字，不合法
//  若左边界等于右边界，则左右各缩小一格，继续判断
//2.暴力：遍历所有字串
//	遍历所有字串的时间复杂度为O(N^2)
//	当数字中每一位都相等，最差时间复杂度为O(N^3)，因为此时需要不断的缩小范围
//3.优化：区间dp，可将时间复杂度压缩为O(N^2)
//	区间dp省去了缩小范围的操作，只需要检测[i+1][j-1]范围是否合法即可

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