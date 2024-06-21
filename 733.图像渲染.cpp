// https://leetcode.cn/problems/flood-fill/description/
// ��һ���� m x n �Ķ�ά���������ʾ��ͼ�� image ������ image[i][j] ��ʾ��ͼ��������ֵ��С��
// ��Ҳ�������������� sr ,  sc �� newColor ����Ӧ�ô����� image[sr][sc] ��ʼ��ͼ����� ��ɫ��� ��
// Ϊ����� ��ɫ���� ���ӳ�ʼ���ؿ�ʼ����¼��ʼ����� ���������ĸ������� ����ֵ���ʼ������ͬ���������ص�
// �����ټ�¼���ĸ������Ϸ������������ص������Ƕ�Ӧ �ĸ������� ����ֵ���ʼ������ͬ���������ص㣬�������ظ��ù��̡��������м�¼�����ص����ɫֵ��Ϊ newColor ��
// ��󷵻� ������ɫ��Ⱦ���ͼ�� ��
class Solution
{
public:
    int prev;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;
        m = image.size(), n = image[0].size();
        dfs(image, sr, sc, color);
        return image;
    }

    void dfs(vector<vector<int>> &image, int i, int j, int color)
    {
        prev = image[i][j];
        image[i][j] = color;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && prev == image[x][y])
                dfs(image, x, y, color);
        }
        return;
    }
};