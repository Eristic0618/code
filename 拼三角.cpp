//给出6根棍子，能否在选出3根拼成一个三角形的同时剩下的3根也能组成一个三角形?
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int a[6];
int check[6];
int flag1, flag2;
int g1, g2, g3;

void dfs(int deap)
{
	if (flag1 && flag2)
		return;
	if (deap == 4)
	{
		vector<int> v1, v2;
		v1.push_back(g1);
		v1.push_back(g2);
		v1.push_back(g3);
		sort(v1.begin(), v1.end());
		if ((v1[0] + v1[1] > v1[2]) && (v1[2] - v1[1] < v1[0]))
		{
			flag1 = 1;
			for (int i = 0; i < 6; i++)
			{
				if (!check[i])
					v2.push_back(a[i]);
			}
			sort(v2.begin(), v2.end());
			if ((v2[0] + v2[1] > v2[2]) && (v2[2] - v2[1] < v2[0]))
				flag2 = 1;
		}
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		if (flag1 && flag2)
			return;
		if (deap == 1 && !check[i])
		{
			g1 = a[i];
			check[i] = 1;
			dfs(2);
			check[i] = 0;
			g1 = 0;
		}
		else if (deap == 2 && !check[i])
		{
			g2 = a[i];
			check[i] = 1;
			dfs(3);
			check[i] = 0;
			g2 = 0;
		}
		else if (deap == 3 && !check[i])
		{
			g3 = a[i];
			check[i] = 1;
			dfs(4);
			check[i] = 0;
			g3 = 0;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		flag1 = 0;
		flag2 = 0;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 6; i++)
		{
			scanf("%d", a + i);
		}
		dfs(1);
		if (flag1 && flag2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}