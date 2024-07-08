// https://www.luogu.com.cn/problem/P8599
// 100 ���Ա�ʾΪ����������ʽ��
// ע���������������У����� 1 ~ 9�ֱ������ֻ����һ�Σ������� 0����
// ���������Ĵ�������100 �� 11�ֱ�ʾ����
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0;
    int n;
    cin >> n;
    do
    {
        int intnum = 0;
        for (int i = 0; i < 7; i++)
        {
            intnum = intnum * 10 + arr[i];
            int mol = 0;
            for (int j = i + 1; j < 8; j++)
            {
                mol = mol * 10 + arr[j];
                int den = 0;
                for (int k = j + 1; k < 9; k++)
                {
                    den = den * 10 + arr[k];
                }
                if (mol % den == 0 && intnum + (mol / den) == n)
                    count++;
            }
        }
    } while (next_permutation(arr, arr + 9));
    cout << count << endl;
    return 0;
}