//https://www.acwing.com/problem/content/801/
#include <bits/stdc++.h>
using namespace std;

#define N 1000010

int n, len;
int a[N];
int hs[N]; //��ϣ���¼������Ԫ������

int main()
{
    cin >> n;
    for(int i = 0 ; i < n; i++)
        cin >> a[i];
    int l = 0, r = 0; //˫ָ��
    while(r < n)
    {
        hs[a[r]]++;
        while(hs[a[r]] > 1) //���ظ�Ԫ��
        {
            hs[a[l]]--;
            l++;
        }
        len = max(len, r - l + 1);
        r++;
    }
    cout << len << endl;
    return 0;
}