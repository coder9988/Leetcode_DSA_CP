# Last updated: 10/11/2026, 5:45:56 PM
1class Solution:
2    def sumOfSquares(self, nums: List[int]) -> int:
3        i = 1
4        sm = nums[0]**2
5        for i in range(1,len(nums)):
6            if len(nums)%(i+1) == 0:
7                sm+=nums[i]**2
8        return sm