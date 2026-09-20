# Last updated: 9/20/2026, 8:17:50 PM
1class Solution:
2
3    def solve(self, dp, n):
4        if n == 0 or n == 1:
5            return n
6
7        if dp[n] != -1:
8            return dp[n]
9
10        dp[n] = self.solve(dp, n-1) + self.solve(dp, n-2)
11        return dp[n]
12
13    def fib(self, n):
14        dp = [-1] * (n+1)
15        return self.solve(dp, n)