// Last updated: 4/19/2026, 7:50:32 PM
1class Solution {
2public:
3    int solve( vector<int> &dp,int n)
4    {
5        if(n==0 || n==1)
6        {
7            return 1;
8        }
9        if(dp[n]!=-1) return dp[n];
10        return dp[n] = solve(dp,n-1) + solve(dp,n-2);
11    }
12    int climbStairs(int n) {
13        vector<int> dp(n+1,-1);
14        return solve(dp,n);
15    }
16};