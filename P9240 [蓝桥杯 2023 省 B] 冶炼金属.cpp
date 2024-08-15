// https : // www.luogu.com.cn/problem/P9240
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// ���ֲ���
int main()
{
    int N;
    cin >> N;
    vector<vector<int>> note(N, vector<int>(2));
    int left = 1, right = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> note[i][0] >> note[i][1];
        right = max(right, note[i][0]);
    }
    int tmp = right;     // ����һ��right��ֵ
    while (left < right) // ������˵�
    {
        int mid = left + (right - left) / 2;
        int flag = 1; // ����Ƿ����м�¼������
        for (int i = 0; i < N; i++)
        {
            if (note[i][0] / mid > note[i][1]) // ת���ʵ���
            {
                left = mid + 1;
                flag = 0;
            }
            else if (note[i][0] / mid < note[i][1]) // ת���ʸ���
            {
                right = mid; // right���ܵ���mid-1��������������ȷ����ķ���
                flag = 0;
            }
        }
        if (flag) // ���ȫ������˵��mid����ȷ�������ڣ����ǲ�һ������˵�
            right = mid;
    }
    // ��ѭ������˵��left��right�ص�����ʱ��Ϊ��˵�
    int begin = left;    // ������˵�
    right = tmp;         // ����rightֵ
    while (left < right) // �����Ҷ˵㣬��Ҫ�޸�һЩϸ��
    {
        int mid = left + (right - left + 1) / 2; // ������Ԫ��Ϊż����ʱ��ȡ�ұߵ��е�
        int flag = 1;
        for (int i = 0; i < N; i++)
        {
            if (note[i][0] / mid < note[i][1])
            {
                right = mid - 1;
                flag = 0;
            }
        }
        if (flag)
            left = mid; // left���ܵ���mid+1��������������ȷ����ķ���
    }
    // ��ѭ������˵��left��right�ص�����ʱ��Ϊ�Ҷ˵�
    int end = right; // �����Ҷ˵�
    cout << begin << " " << end;
    return 0;
}