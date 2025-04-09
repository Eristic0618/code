#https://leetcode.cn/problems/maximum-unique-subarray-sum-after-deletion/
class Solution:
    def maxSum(self, nums: List[int]) -> int:
        s = set(x for x in nums if x >= 0)
        if len(s) > 0:
            return sum(s)
        else:
            return max(nums)