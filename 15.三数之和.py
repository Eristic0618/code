class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        size = len(nums)
        for fi in range(size):
            if fi != 0 and nums[fi] == nums[fi-1]:
                continue
            se = fi + 1
            th = size-1
            sum = 0 - nums[fi]
            while se < th:
                if se != fi + 1 and nums[se] == nums[se-1]:
                    se += 1
                    continue
                while se < th and nums[se] + nums[th] > sum:
                    th -= 1
                if se == th:
                    break
                if nums[se] + nums[th] == sum:
                    res.append([nums[fi], nums[se], nums[th]])
                se += 1
        return res