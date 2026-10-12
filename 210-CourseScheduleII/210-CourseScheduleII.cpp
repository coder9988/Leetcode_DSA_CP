// Last updated: 10/12/2026, 11:19:13 PM
1class Solution {
2public:
3    bool dfs(vector<vector<int>>& graph, int node,
4             vector<bool>& vis, vector<bool>& incur,
5             vector<int>& ans) {
6
7        vis[node] = true;
8        incur[node] = true;
9
10        for (int neighbor : graph[node]) {
11            if (!vis[neighbor]) {
12                if (dfs(graph, neighbor, vis, incur, ans))
13                    return true;
14            }
15            else if (incur[neighbor]) {
16                return true;
17            }
18        }
19
20        incur[node] = false;
21        ans.push_back(node);
22        return false;
23    }
24
25    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
26        vector<vector<int>> graph(numCourses);
27        vector<bool> vis(numCourses, false);
28        vector<bool> incur(numCourses, false);
29        vector<int> ans;
30
31        for (auto& p : prerequisites) {
32            graph[p[0]].push_back(p[1]);
33        }
34
35        for (int i = 0; i < numCourses; i++) {
36            if (!vis[i]) {
37                if (dfs(graph, i, vis, incur, ans))
38                    return {};
39            }
40        }
41        return ans;
42    }
43};