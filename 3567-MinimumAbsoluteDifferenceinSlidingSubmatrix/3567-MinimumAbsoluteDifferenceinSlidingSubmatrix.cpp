// Last updated: 3/20/2026, 7:54:36 PM
1class Solution {
2public:
3    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
7
8        for (int i = 0; i <= m - k; i++) {
9            for (int j = 0; j <= n - k; j++) {
10                vector<int> v;
11                for (int x = i; x < i + k; x++)
12                    for (int y = j; y < j + k; y++)
13                        v.push_back(grid[x][y]);
14
15                sort(v.begin(), v.end());
16                v.erase(unique(v.begin(), v.end()), v.end());
17
18                if (v.size() <= 1) {
19                    ans[i][j] = 0;
20                } else {
21                    int mn = INT_MAX;
22                    for (int p = 0; p < (int)v.size() - 1; p++)
23                        mn = min(mn, v[p+1] - v[p]);
24                    ans[i][j] = mn;
25                }
26            }
27        }
28        return ans;
29    }
30};