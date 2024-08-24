// https : // www.luogu.com.cn/problem/P9236#submit
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;

int main()
{
    cin >> n;
    ll *arr = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll pow = 1, sum = 0;  
    for (int i = 0; i < 20; i++) //������20��������λ 
    {
        ll counti = 0, oddnum = 0, evenum = 0, range = 0; 
		//countiͳ��1��ǰ׺�ͣ�oddnumͳ������ǰ׺�͵ĸ���
        //evenumͳ��ż��ǰ׺�͵ĸ�����rangeͳ���й���������� 
        for (int j = 0; j < n; j++) //����n������ 
        {
            if (arr[j] & 1) //��λ��1����Ϊ1��˵�����λΪ1������Ϊ0 
                counti++; //����ǰ׺�� 
            if (counti % 2 == 1) //ǰ׺��Ϊ����
            {
                range += 1 + evenum; //�����й���������� 
                oddnum++; //����ǰ׺�͵ĸ���+1 
            }
            else //ǰ׺��Ϊż�� 
            {
                range += oddnum; //�����й���������� 
                evenum++; //ż��ǰ׺�͵ĸ���+1 
            }
            arr[j] >>= 1; //��λ 
        }
        sum += range * pow; //����λ���Խ���Ĺ���ֵ 
        pow *= 2; //����pow 
    }
    cout << sum;
    return 0;
}