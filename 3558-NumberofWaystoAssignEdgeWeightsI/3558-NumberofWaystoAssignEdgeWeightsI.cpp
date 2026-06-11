// Last updated: 6/11/2026, 8:56:38 PM
1class Solution {
2public:
3    int MOD = 1e9 + 7;
4    int dfs(vector<vector<int>>& adj, int curr, int parent){
5        int depth = 0;
6        for(auto node : adj[curr]){
7            if(node == parent) continue;
8            depth = max(depth, dfs(adj, node, curr) + 1);
9        }
10        return depth;
11    }
12    int assignEdgeWeights(vector<vector<int>>& edges) {
13        int n = edges.size() + 1;
14        vector<vector<int>> adj(n + 1);
15        
16        for(auto edge : edges){
17            adj[edge[0]].push_back(edge[1]);
18            adj[edge[1]].push_back(edge[0]);
19        }
20
21        int depth = dfs(adj, 1, 0);
22        
23        long long ans = 1; 
24        while(--depth){
25            ans = (ans * 2) % MOD;
26        }
27        return ans;
28    }
29};