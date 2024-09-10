// https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&&tqId=21224&rp=5&ru=/activity/oj&qru=/ta/huawei/question-ranking
// 计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。（注：字符串末尾不以空格为结尾）
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int ans = 0;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
            break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}