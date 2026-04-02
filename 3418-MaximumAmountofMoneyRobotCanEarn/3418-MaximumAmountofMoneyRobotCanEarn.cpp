// Last updated: 4/2/2026, 7:22:14 PM
1int dp[500][500][3]; // DP array 
2class Solution {
3    static int f(int i, int j, int k, vector<vector<int>>& coins) {
4        if (i==0 && j==0) {// // Base case 
5            if (k>0) return max(0, coins[0][0]); 
6            return coins[0][0]; 
7        }
8        if (i<0 || j<0 || k<0) return -1e9;
9
10        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];
11        const int x=coins[i][j];
12        int ans=x+max(f(i-1, j, k, coins), f(i, j-1, k, coins));
13        // If x<0, k>0 neutralize robber once
14        if (x<0 && k>0) 
15            ans=max({ans, f(i-1, j, k-1, coins), f(i, j-1, k-1, coins)});
16        
17        return dp[i][j][k]=ans;
18    }
19
20public:
21    static int maximumAmount(vector<vector<int>>& coins) {
22        const int r=coins.size(), c=coins[0].size();
23        // Initialize DP with INT_MIN
24        fill(&dp[0][0][0], &dp[0][0][0]+500*500*3, INT_MIN);
25        return f(r-1, c-1, 2, coins);
26    }
27};
28