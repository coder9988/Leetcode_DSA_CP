# Last updated: 9/21/2026, 10:29:08 AM
1class Solution:
2    def maxProfit(self, prices: list[int]) -> int:
3        buy = 0
4        sold = 1
5        ans = 0
6        while sold<len(prices):
7            if prices[sold] > prices[buy]:
8                ans = max(ans,prices[sold] - prices[buy])
9            else:
10                buy = sold
11            sold+=1
12        return ans
13