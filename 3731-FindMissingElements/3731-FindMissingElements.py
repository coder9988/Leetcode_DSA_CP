# Last updated: 8/4/2026, 11:10:55 PM
1class Solution(object):
2    def findMissingElements(self, nums):
3        nums.sort()
4        l = []
5        for i in range(nums[0],nums[-1]+1):
6            if i not in nums:
7                l.append(i)
8        return l
9        