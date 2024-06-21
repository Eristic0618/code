// https://leetcode.cn/problems/flood-fill/description/
// 有一幅以 m x n 的二维整数数组表示的图画 image ，其中 image[i][j] 表示该图画的像素值大小。
// 你也被给予三个整数 sr ,  sc 和 newColor 。你应该从像素 image[sr][sc] 开始对图像进行 上色填充 。
// 为了完成 上色工作 ，从初始像素开始，记录初始坐标的 上下左右四个方向上 像素值与初始坐标相同的相连像素点
// 接着再记录这四个方向上符合条件的像素点与他们对应 四个方向上 像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为 newColor 。
// 最后返回 经过上色渲染后的图像 。
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