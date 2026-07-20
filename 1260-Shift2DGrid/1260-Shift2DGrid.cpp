// Last updated: 7/21/2026, 12:45:50 AM
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        if (!k) return grid;
5        int r = grid.size(), c = grid[0].size();
6        int n = r * c;
7
8        k = k % n;
9        if (!k) return grid;
10
11        auto shift = [&](int i, int j) {
12            while (i < j) {
13                swap(grid[i / c][i % c], grid[j / c][j % c]);
14                i++;
15                j--;
16            }
17        };
18
19        shift(0, n - 1);
20        shift(0, k - 1);
21        shift(k, n - 1);
22
23        return grid;
24    }
25};