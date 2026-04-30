// Last updated: 4/30/2026, 7:35:39 PM
1short dp[200][200][1001];
2class Solution {
3public:
4    int k;
5    const short NO=SHRT_MIN;
6    int f(int i, int j, int c, vector<vector<int>>& grid){
7        if (i<0 || j<0 || c>k) return NO;
8        if (dp[i][j][c]!=-1) return dp[i][j][c];
9        int x=grid[i][j], cost=c+(x!=0);
10        if (cost>k) 
11            return dp[i][j][c]=NO;
12        if (i==0 && j==0)
13            return dp[i][j][c]=grid[0][0];
14        return dp[i][j][c]=x+max(f(i-1, j, cost, grid), f(i, j-1, cost, grid));
15    }
16    int maxPathScore(vector<vector<int>>& grid, int k) {
17        this->k=k;
18        const int row=grid.size(), col=grid[0].size();
19        for(int i=0; i<row; i++)
20            for(int j=0; j<col; j++)
21                memset(dp[i][j], -1, (k+1)*sizeof(short));
22        int ans=f(row-1, col-1, 0, grid);
23        return ans<0?-1:ans;
24    }
25};
26
27const auto init = []() noexcept {
28    ios::sync_with_stdio(false);
29    cin.tie(nullptr);
30    cout.tie(nullptr);
31    return 'c';
32}();