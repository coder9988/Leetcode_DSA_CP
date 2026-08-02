// Last updated: 8/2/2026, 6:54:26 PM
1class Solution {
2public:
3const int INF = 1e9;
4    int solve(int amount,int i,vector<vector<int>> &dp, vector<int>& coins)
5    {
6        if(amount == 0)
7        {
8            return 0;
9        }
10        if(i==coins.size())
11        {
12            return INF;
13        }
14        if(dp[i][amount]!=-1)
15        {
16            return dp[i][amount];
17        }
18        int take = INF;
19        if(coins[i]<=amount)
20        {
21            take = 1 + solve(amount-coins[i],i,dp,coins);
22        }
23        int notTake = solve(amount,i+1,dp,coins);
24        dp[i][amount] = min(take,notTake);
25        return dp[i][amount];
26    }
27    int coinChange(vector<int>& coins, int amount) {
28        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
29        int ans = solve(amount,0,dp,coins);
30        return (ans==INF)?-1:ans;
31    }
32};