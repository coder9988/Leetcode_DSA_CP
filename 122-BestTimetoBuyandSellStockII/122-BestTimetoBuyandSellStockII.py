# Last updated: 9/21/2026, 11:00:07 AM
1class Solution:
2    def maxProfit(self, prices: list[int]) -> int:
3        profit = 0
4        for i in range(1,len(prices)):
5            if prices[i]>prices[i-1]:
6                profit += prices[i]-prices[i-1]
7        return profit