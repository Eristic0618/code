// https://www.luogu.com.cn/problem/P8787
#include <bits/stdc++.h>

#define ll long long
using namespace std;
ll H[200050]; //���Ӹ߶�
int cut[200050] = { 0 };//��¼ÿ�����ӿɱ���������
//���ܷ�����������ᱬջ

//˼·��̰��
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
			temp = sqrtl((temp / 2) + 1);//���ÿ�����ӿɱ���������
			cut[i]++;
		}
		maxcut = max(maxcut, cut[i]); //��¼���ֵ
	}
	for (int i = maxcut; i > 0; i--) //���ܱ������ε����ӿ�ʼ��
	{
		for (int j = 0; j < n; j++)
		{
			if (cut[j] == i) //����i��ɿ���
			{
				if (H[j] != H[j + 1]) //������˵����һ��������ͬ�߶ȵģ�ֻ�ܼ���һ��
				//��Ϊ���鿪�Ĺ������Բ��õ���Խ��
					ans++;
				cut[j]--; //��������-1
				H[j] = sqrtl((H[j] / 2) + 1); //�߶ȸ���
			}
		}
	}
	printf("%d", ans);
	return 0;
}