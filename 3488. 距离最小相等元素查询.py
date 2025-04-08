#https://leetcode.cn/problems/closest-equal-element-queries/description/
class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        num2index = defaultdict(list) #哈希表，value是list
        ret = []
        for i, x in enumerate(nums): #取nums的所有下标i和元素x
            num2index[x].append(i) #在哈希表中保存x出现的所有下标i
        for v in num2index.values(): #取哈希表中所有列表
            v.insert(0, v[-1] - len(nums)) #添加前哨兵（相当于数组第一个x的左边最近x下标）
            v.append(len(nums) + v[1]) #添加后哨兵（相当于数组最后一个x的右边最近x下标）
        for i in queries: #取queries中所有要查询的下标i
            p = num2index[nums[i]] #找到i对应的元素x的下标列表
            if len(p) == 3: #如果列表长度为3，去掉前后哨兵变为1，则数组中只有一个x
                ret.append(-1)
            else:
                j = bisect_left(p, i) #用二分在列表中查找下标i所在的下标
                ret.append(min(i - p[j-1], p[j+1] - i)) #选择i到左边和右边最近的距离
        return ret