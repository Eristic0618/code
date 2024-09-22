#https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/?envType=study-plan-v2&envId=top-100-liked
#给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s: return 0
        lookup = set()
        left = 0
        ans = 0
        cur = 0
        n = len(s)
        for i in range(n):
            cur += 1
            while s[i] in lookup:
                lookup.remove(s[left])
                left += 1
                cur -= 1
            if cur > ans : ans = cur
            lookup.add(s[i])
        return ans
        