# Last updated: 10/11/2026, 4:16:51 PM
1class Solution:
2    def twoSum(self, nums: list[int], target: int) -> list[int]:
3        need = {}
4        for i in range(len(nums)):
5            if nums[i] in need:
6                return [i,need[nums[i]]]
7            need[target-nums[i]] = i
8        return []
9
10