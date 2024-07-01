// https://www.luogu.com.cn/problem/P8597
// ���Ϸ����ų�һ�ŵ�����Ӳ�ҡ������� * ��ʾ���棬�� o ��ʾ���棨��Сд��ĸ�������㣩
// ������������� **oo***oooo�����ͬʱ��ת��ߵ�����Ӳ�ң����Ϊ oooo***oooo��
// ����С���������ǣ������֪�˳�ʼ״̬��Ҫ�ﵽ��Ŀ��״̬��ÿ��ֻ��ͬʱ��ת���ڵ�����Ӳ��
// ��ô���ض��ľ��棬����Ҫ�������ٴ��أ�
#include <iostream>
#include <string>
using namespace std;

void roll(char &c)
{
    if (c == '*')
        c = 'o';
    else
        c = '*';
}

int main()
{
    string ori;
    string des;
    cin >> ori >> des;
    int i = 0, j = 0;
    int count = 0;
    while (i < ori.size())
    {
        if (ori[i] != des[j])
        {
            roll(ori[i]);
            roll(ori[i + 1]);
            count++;
        }
        i++;
        j++;
    }
    cout << count << endl;
    return 0;
}