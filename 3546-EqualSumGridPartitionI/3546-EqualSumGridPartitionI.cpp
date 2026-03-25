// Last updated: 3/25/2026, 10:37:20 PM
1class Solution {
2public:
3    bool canPartitionGrid(vector<vector<int>>& grid) {
4        int m = grid.size(), n = grid[0].size();
5        long long total = 0;
6        
7        for (auto &row : grid)
8            for (int x : row)
9                total += x;
10        
11        if (total % 2) return false;
12        
13        long long target = total / 2, sum = 0;
14        
15        for (int i = 0; i < m - 1; i++) {
16            for (int j = 0; j < n; j++)
17                sum += grid[i][j];
18            if (sum == target) return true;
19        }
20        
21        sum = 0;
22        
23        for (int j = 0; j < n - 1; j++) {
24            for (int i = 0; i < m; i++)
25                sum += grid[i][j];
26            if (sum == target) return true;
27        }
28        
29        return false;
30    }
31};