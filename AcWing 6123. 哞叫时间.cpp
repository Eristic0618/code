//https://www.acwing.com/problem/content/description/6126/
// 纯暴力枚举
#include <iostream>
#include <string>
using namespace std;

int n, f;
string str;
string s[26*25]; //abb形式字符串中，a可以枚举26种字符，而b因为不能与a相同，只能枚举25种
int cnt[26*25]; //记录每种abb出现次数
int ans;

int main()
{
    int index = 0;
    for(int a = 'a'; a <= 'z'; a++) //枚举所有abb子串
    {
        for(int b = 'a'; b <= 'z'; b++)
        {
            if(a == b) //a b不能相同
                continue;
            string s0;
            s0 += a, s0 += b, s0 += b;
            s[index++] = s0;
        }
    }
    cin >> n >> f;
    cin >> str;
    for(int i = 0; i < 26*25; i++) //遍历所有abb
    {
        for(int j = 0; j < n-2; j++) //从头到尾遍历原字符串
        {
            string s1 = str.substr(j, 3); //取长度为3的子串
            if(s[i] == s1) //匹配
                cnt[i]++; //出现次数+1
        }
        if(cnt[i] == f-1) //abb串出现次数为f-1，即可能可以通过修改一个字符再出现一次
        {
            for(int j = 0; j < n-2; j++) //再次遍历原字符串
            {
                int flag = 0; //在修改原串时，如果刚好把已经出现过的abb也同时修改掉了次数也不会增多
                string s1 = str.substr(j, 3);
                for(int x = -2; x <= 2; x++)
                {
                    //在j-2到j+2范围内长度为3的子串，如果出现了abb，且s1刚好和abb相差一个字符
                    //则修改字符必定会影响到出现过的abb子串，这是由字符串格式决定的
                    if(j+x < n-2 && j+x >= 0) //防止越界
                    {
                        string s2 = str.substr(j+x, 3);
                        if(s2 == s[i]) //范围内出现过abb
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
                    (s1[1] == s[i][1] && s1[2] == s[i][2])) //有两个字符相同
                {
                    cnt[i]++;
                    break; //只能有一个字符被修改
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