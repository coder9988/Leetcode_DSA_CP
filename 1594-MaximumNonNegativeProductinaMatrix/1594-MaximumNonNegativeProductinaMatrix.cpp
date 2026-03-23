// Last updated: 3/23/2026, 10:36:30 PM
1int64_t dp[15][15][2];
2class Solution {
3public:
4    static int maxProductPath(vector<vector<int>>& grid) {
5        const int r=grid.size(), c=grid[0].size(), MOD=1e9+7;
6        int64_t p=dp[0][0][0]=dp[0][0][1]=grid[0][0];
7        for(int j=1; j<c; j++){
8            p*=grid[0][j];
9            dp[0][j][0]=dp[0][j][1]=p;
10        }
11        p=grid[0][0];
12        for(int i=1; i<r; i++){
13            p*=grid[i][0];
14            dp[i][0][0]=dp[i][0][1]=p;
15            for(int j=1; j<c; j++){
16                int x=grid[i][j];
17                auto [minP, maxP]=minmax({x*dp[i][j-1][0], x*dp[i][j-1][1], x*dp[i-1][j][0], x*dp[i-1][j][1]});
18                dp[i][j][0]=minP, dp[i][j][1]=maxP;
19            }
20        }
21        int64_t ans=dp[r-1][c-1][1];
22        return ans<0?-1: ans%MOD;
23    }
24};