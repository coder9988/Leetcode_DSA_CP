// Last updated: 7/12/2026, 1:41:13 AM
1class Solution {
2public:
3    int countCompleteComponents(int n, vector<vector<int>>& edges) {
4        vector<vector<int>> adj(n);
5
6        for (auto &e : edges) {
7            adj[e[0]].push_back(e[1]);
8            adj[e[1]].push_back(e[0]);
9        }
10
11        vector<bool> vis(n, false);
12        int ans = 0;
13
14        for (int i = 0; i < n; i++) {
15            if (vis[i]) continue;
16
17            queue<int> q;
18            q.push(i);
19            vis[i] = true;
20
21            int nodes = 0;//number of nodes in the component
22            int edgeCount = 0; //total edges in the component
23
24            while (!q.empty()) {
25                int u = q.front();
26                q.pop();
27
28                nodes++;
29                edgeCount += adj[u].size();
30
31                for (int v : adj[u]) {
32                    if (!vis[v]) {
33                        vis[v] = true;
34                        q.push(v);
35                    }
36                }
37            }
38
39            edgeCount /= 2;
40
41            if (edgeCount == nodes * (nodes - 1) / 2)
42                ans++;
43        }
44
45        return ans;
46    }
47};