// Last updated: 10/8/2026, 11:33:40 PM
1class Solution {
2public:
3    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
4        int n = graph.size();
5
6        vector<vector<int>> rev(n);
7        vector<int> degree(n);
8        queue<int> q;
9
10        for(int i = 0; i < n; i++)
11        {
12            degree[i] = graph[i].size();
13
14            for(int neighbor : graph[i])
15            {
16                rev[neighbor].push_back(i);
17            }
18
19            if(degree[i] == 0)
20                q.push(i);
21        }
22
23        vector<bool> safe(n, false);
24
25        while(!q.empty())
26        {
27            int node = q.front();
28            q.pop();
29
30            safe[node] = true;
31
32            for(int prev : rev[node])
33            {
34                degree[prev]--;
35
36                if(degree[prev] == 0)
37                    q.push(prev);
38            }
39        }
40
41        vector<int> ans;
42
43        for(int i = 0; i < n; i++)
44        {
45            if(safe[i])
46                ans.push_back(i);
47        }
48
49        return ans;
50    }
51};