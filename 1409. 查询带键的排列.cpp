// https://leetcode.cn/problems/queries-on-a-permutation-with-key/description/
//  ����һ������������ queries ����ȡֵ��Χ�� 1 �� m ֮�䡣 ����������¹���˳�������� queries[i]���� i=0 �� i=queries.length-1����
//  ���ȣ�����һ������ P=[1,2,3,...,m]��
//  ���ڵ�ǰ�� i ���ҵ� queries[i] ������ P �е�λ�ã��� 0 ��ʼ��������Ȼ�����Ƶ����� P �Ŀ�ͷ�����±�Ϊ 0 ������
//  ע�⣬ queries[i] �Ĳ�ѯ����� queries[i] �� P ���ƶ�ǰ��λ�á�
//  ����һ�����飬�����Ӹ���  queries �в�ѯ���Ľ����
class Solution
{
public:
    int n, sz;
    vector<int> b;

    int count(int p)
    {
        int res = 0;
        while (p)
        {
            res += b[p];
            p -= p & (-p);
        }
        return res;
    }

    void add(int p, int x)
    {
        while (p <= sz)
        {
            b[p] += x;
            p += p & (-p);
        }
    }

    vector<int> processQueries(vector<int> &queries, int m)
    {
        n = queries.size();
        sz = m + n;
        b.resize(sz + 1);
        vector<int> ans;
        vector<int> index(m + 1);    // ���P��Ԫ������״�����е��±�
        for (int i = 1; i <= m; i++) // ��ʼ��
        {
            index[i] = n + i;
            add(n + i, 1); // 1Ϊ�ǿգ�0Ϊ��
        }
        for (int i = 0; i < n; i++)
        {
            int cur = index[queries[i]];
            add(cur, -1);              // ��ԭ��λ���ÿ�
            ans.push_back(count(cur)); // ����ԭλ��ǰ���м���Ԫ��
            index[queries[i]] = n - i; // �����µ�λ��
            add(n - i, 1);
        }
        return ans;
    }
};