// https://leetcode.cn/problems/hanota-lcci/description/
// �ھ��人ŵ�������У��� 3 �����Ӽ� N ����ͬ��С�Ĵ���Բ�̣����ӿ��Ի�������һ�����ӡ�һ��ʼ�������������϶��°������������ڵ�һ��������(��ÿһ������ֻ�ܷ��ڸ������������)���ƶ�Բ��ʱ�ܵ���������:
// (1) ÿ��ֻ���ƶ�һ������;
// (2) ����ֻ�ܴ����Ӷ��˻����Ƶ���һ������;
// (3) ����ֻ�ܵ��ڱ�����������ϡ�
class Solution
{
public:
    void dfs(vector<int> &x, vector<int> &y, vector<int> &z, size_t n)
    {
        if (n == 1)
        {
            z.push_back(x.back());
            x.pop_back();
            return;
        }
        dfs(x, z, y, n - 1);
        z.push_back(x.back());
        x.pop_back();
        dfs(y, x, z, n - 1);
    }

    void hanota(vector<int> &A, vector<int> &B, vector<int> &C)
    {
        dfs(A, B, C, A.size());
    }
};