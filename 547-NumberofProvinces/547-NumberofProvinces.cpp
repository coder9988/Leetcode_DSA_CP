// Last updated: 7/10/2026, 1:42:24 PM
1class Solution {
2public:
3    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int city) {
4        vis[city] = true;
5        for (int i = 0; i < isConnected.size(); i++) {
6            if (isConnected[city][i] == 1 && !vis[i]) {
7                vis[i] = true;
8                dfs(isConnected, vis, i);
9            }
10        }
11    }
12    int findCircleNum(vector<vector<int>>& isConnected) {
13
14        int s = isConnected.size();
15        vector<bool> visited(s, false);
16        int province = 0;
17        for (int i = 0; i < s; i++) {
18            if (!visited[i]) {
19                dfs(isConnected, visited, i);
20                province += 1;
21            }
22        }
23        return province;
24    }
25};