// Last updated: 10/8/2026, 7:29:29 PM
1class Solution {
2public:
3    bool dfs(int start, vector<vector<int>> &graph, vector<bool>& vis,
4             vector<bool>& path) {
5        vis[start] = true;
6        path[start] = true;
7        for (int neighbor : graph[start]) {
8            if (!vis[neighbor]) {
9                if (dfs(neighbor, graph, vis, path)) {
10                    return true;
11                }
12            } else if (path[neighbor]) {
13                return true;
14            }
15        }
16        path[start] = false;
17        return false;
18    }
19    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
20        vector<bool> path(numCourses, false);
21        vector<bool> vis(numCourses, false);
22        vector<vector<int>> graph(numCourses);
23        for (auto edges : prerequisites) {
24            graph[edges[1]].push_back(edges[0]);
25        }
26        for (int i = 0; i < numCourses; i++) {
27            if (!vis[i]) {
28                if (dfs(i, graph, vis, path))
29                    return false;
30            }
31        }
32        return true;
33    }
34};