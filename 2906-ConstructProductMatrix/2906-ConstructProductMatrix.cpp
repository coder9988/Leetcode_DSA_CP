// Last updated: 3/24/2026, 9:45:29 PM
1class Solution {
2public:
3    static vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
4        const int N=12345, n=grid.size(), m=grid[0].size();
5        vector<vector<int>> ans(n, vector<int>(m));
6        uint64_t pref=1, suf=1;
7        for(int i=0; i<n; i++)
8            for(int j=0; j<m; j++){
9                ans[i][j]=pref;
10                pref=pref*grid[i][j]%N;
11            }
12        for(int i=n-1; i>=0; i--)
13            for(int j=m-1; j>=0; j--){
14                ans[i][j]=ans[i][j]*suf%N;
15                suf=suf*grid[i][j]%N;
16            }
17        return ans;
18    }
19};