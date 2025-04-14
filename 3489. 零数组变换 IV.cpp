//https://leetcode.cn/problems/zero-array-transformation-iv/description/
class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int sum = 0;
            for(int i = 0; i < nums.size(); i++)
                sum += nums[i];
            if(sum == 0) //特判
                return 0;
            
            vector<vector<bool>> f(nums.size()); //01背包，每一个nums[i]都是一个背包，f[i][j]=true表示容量为j的包最终能够被填满
            //询问里的数相当于对应背包能够选择的物品
            for(int i = 0;i < nums.size(); i++) //遍历
            {
                f[i].resize(nums[i]+1); //按照nums[i]的值初始化数组
                f[i][0] = true; //容量为0的包已经为填满状态
            }
            for(int k = 0; k < queries.size(); k++) //遍历所有询问
            {
                for(int i = queries[k][0];i <= queries[k][1] ; i++) //遍历背包
                {
                    for(int j = nums[i]; j >= queries[k][2]; j--) //遍历所有可能的容量
                    {
                        f[i][j] = f[i][j] || f[i][j-queries[k][2]]; //不选物品或选物品
                    }
                    int flag = 0;
                    for(int j = 0; j < nums.size(); j++) //循环判断一遍是否所有的背包都能够被装满
                    {
                        if(f[j][nums[j]] == false) //还有背包不能被装满，继续循环
                            flag = 1;
                    }
                    if(!flag) //结束循环，
                        return k+1;
                }
            }
            return -1;
        }
    };