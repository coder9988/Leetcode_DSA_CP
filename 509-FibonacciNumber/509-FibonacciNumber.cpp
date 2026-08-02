// Last updated: 8/2/2026, 5:25:00 PM
1class Solution {
2public:
3    int solve(int n,vector<int> &dp)
4    {
5        if(n ==1 || n == 0)
6        {
7            return n;
8        }
9        if(n<0)
10        {
11            return 0;
12        }
13        if(dp[n]!=-1)
14        {
15            return dp[n];
16        }
17        dp[n] = solve(n-1,dp) + solve(n-2,dp);
18        return dp[n];
19    }
20    int fib(int n) {
21        vector<int> dp(n+1,-1);
22        return solve(n,dp);
23    }
24};