//https://www.acwing.com/problem/content/description/6126/
// ������ö��
#include <iostream>
#include <string>
using namespace std;

int n, f;
string str;
string s[26*25]; //abb��ʽ�ַ����У�a����ö��26���ַ�����b��Ϊ������a��ͬ��ֻ��ö��25��
int cnt[26*25]; //��¼ÿ��abb���ִ���
int ans;

int main()
{
    int index = 0;
    for(int a = 'a'; a <= 'z'; a++) //ö������abb�Ӵ�
    {
        for(int b = 'a'; b <= 'z'; b++)
        {
            if(a == b) //a b������ͬ
                continue;
            string s0;
            s0 += a, s0 += b, s0 += b;
            s[index++] = s0;
        }
    }
    cin >> n >> f;
    cin >> str;
    for(int i = 0; i < 26*25; i++) //��������abb
    {
        for(int j = 0; j < n-2; j++) //��ͷ��β����ԭ�ַ���
        {
            string s1 = str.substr(j, 3); //ȡ����Ϊ3���Ӵ�
            if(s[i] == s1) //ƥ��
                cnt[i]++; //���ִ���+1
        }
        if(cnt[i] == f-1) //abb�����ִ���Ϊf-1�������ܿ���ͨ���޸�һ���ַ��ٳ���һ��
        {
            for(int j = 0; j < n-2; j++) //�ٴα���ԭ�ַ���
            {
                int flag = 0; //���޸�ԭ��ʱ������պð��Ѿ����ֹ���abbҲͬʱ�޸ĵ��˴���Ҳ��������
                string s1 = str.substr(j, 3);
                for(int x = -2; x <= 2; x++)
                {
                    //��j-2��j+2��Χ�ڳ���Ϊ3���Ӵ������������abb����s1�պú�abb���һ���ַ�
                    //���޸��ַ��ض���Ӱ�쵽���ֹ���abb�Ӵ����������ַ�����ʽ������
                    if(j+x < n-2 && j+x >= 0) //��ֹԽ��
                    {
                        string s2 = str.substr(j+x, 3);
                        if(s2 == s[i]) //��Χ�ڳ��ֹ�abb
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag) 
                    continue;
                if((s1[0] == s[i][0] && s1[1] == s[i][1]) ||
                    (s1[0] == s[i][0] && s1[2] == s[i][2]) ||
                    (s1[1] == s[i][1] && s1[2] == s[i][2])) //�������ַ���ͬ
                {
                    cnt[i]++;
                    break; //ֻ����һ���ַ����޸�
                }
            }
        }
        if(cnt[i] >= f)
            ans++;
    }
    cout << ans << endl;
    for(int i = 0;i < 26*25; i++)
    {
        if(cnt[i] >= f)
            cout << s[i] << endl;
    }
    return 0;
}