// https://www.luogu.com.cn/problem/P8787
#include <bits/stdc++.h>

#define ll long long
using namespace std;
ll H[200050]; //竹子高度
int cut[200050] = { 0 };//记录每棵竹子可被砍伐次数
//不能放在主函数里，会爆栈

//思路：贪心
int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	int maxcut = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> H[i];
		ll temp = H[i];
		while (temp - 1)
		{
			temp = sqrtl((temp / 2) + 1);//算出每棵竹子可被砍伐次数
			cut[i]++;
		}
		maxcut = max(maxcut, cut[i]); //记录最大值
	}
	for (int i = maxcut; i > 0; i--) //从能被砍最多次的竹子开始砍
	{
		for (int j = 0; j < n; j++)
		{
			if (cut[j] == i) //等于i则可砍伐
			{
				if (H[j] != H[j + 1]) //如果相等说明这一个区域都是同高度的，只能计算一次
				//因为数组开的够大，所以不用担心越界
					ans++;
				cut[j]--; //砍伐次数-1
				H[j] = sqrtl((H[j] / 2) + 1); //高度更新
			}
		}
	}
	printf("%d", ans);
	return 0;
}