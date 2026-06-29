// Last updated: 6/30/2026, 2:57:55 AM
1class Solution {
2public:
3
4    void checkpath(vector<vector<int>> &adj,int s, vector<bool> &visited)
5    {
6        visited[s] = true;
7        for(int i:adj[s])
8        {
9            if(!visited[i])
10            {
11                checkpath(adj,i,visited);
12            }
13        }
14    }
15    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
16        
17        vector<bool> visited(n,false);
18        vector<vector<int>> adj(n);
19        for(auto &edge:edges)
20        {
21            int u = edge[0];
22            int v = edge[1];
23            adj[u].push_back(v);
24            adj[v].push_back(u);
25        }
26        checkpath(adj,source,visited);
27        return visited[destination];
28    }
29};