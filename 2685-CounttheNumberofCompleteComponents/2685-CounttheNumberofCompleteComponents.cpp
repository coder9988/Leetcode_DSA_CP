// Last updated: 8/14/2026, 7:22:46 PM
1class Solution {
2public:
3    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited,
4             int& vertices, int& edges) {
5        
6        visited[node] = true;
7        vertices++;
8        edges += graph[node].size();
9
10        for(int i:graph[node])
11        {
12            if(!visited[i])
13            {
14                dfs(graph,i,visited,vertices,edges);
15            }
16        }
17    }
18
19    int countCompleteComponents(int n, vector<vector<int>>& edges) {
20        vector<vector<int>> graph(n);
21
22        for (int i = 0; i < edges.size(); i++) {
23            graph[edges[i][0]].push_back(edges[i][1]);
24            graph[edges[i][1]].push_back(edges[i][0]);
25        }
26
27        vector<bool> visited(n, false);
28        int ans = 0;
29        for(int i =0;i<n;i++)
30        {
31            if(!visited[i])
32            {
33            int vertices = 0;
34            int totaldegree = 0;
35            dfs(graph,i,visited,vertices,totaldegree);
36
37            int actualedges = totaldegree/2;
38            int required = vertices*(vertices-1)/2;
39            if(actualedges == required)
40            {
41                ans += 1;
42            }
43            }
44
45        }
46       
47        return ans;
48    }
49};