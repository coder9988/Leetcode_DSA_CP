// Last updated: 4/26/2026, 5:13:15 PM
1int dir[5]={0, 1, 0, -1, 0};
2int r, c;
3class Solution {
4public:
5    static inline bool isOutside(int i, int j, int r, int c){
6        return i<0||i>=r||j<0||j>=c;
7    }
8    static bool dfs(int i, int j, int i0, int j0, int alpha, vector<vector<char>>& grid){
9        grid[i][j]=-alpha;
10        for(int a=0; a<4; a++){
11            const int s=i+dir[a], t=j+dir[a+1];
12            if (isOutside(s, t, r, c) || (s==i0 && t==j0)) continue;
13            if (grid[s][t]==-alpha) return 1;
14            if (grid[s][t]==alpha){
15                if (dfs(s, t, i, j, alpha, grid)) return 1;
16            }
17        }
18        return 0;
19    }
20    static bool containsCycle(vector<vector<char>>& grid) {
21        r=grid.size(), c=grid[0].size();
22        for(int i=0; i<r; i++){
23            for(int j=0; j<c; j++){
24                if (grid[i][j]<0) continue;
25                if (dfs(i, j, -1, -1, grid[i][j], grid)) return 1;
26            }
27        }
28        return 0;
29    }
30};
31
32auto init = []() {
33    ios::sync_with_stdio(0);
34    cin.tie(0);
35    cout.tie(0);
36    return 'c';
37}();