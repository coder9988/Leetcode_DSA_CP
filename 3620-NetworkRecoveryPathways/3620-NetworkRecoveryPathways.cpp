// Last updated: 7/4/2026, 1:41:47 AM
1class Solution {
2public:
3    int n;
4
5    bool find(int limit, unordered_map<int, vector<pair<int,int>>>& adj,
6              vector<bool>& online, vector<int>& topoSort, long long k){
7
8        vector<long long> dist(n, LLONG_MAX);
9        dist[0] = 0;
10
11        for(int node : topoSort){
12            if(dist[node] == LLONG_MAX) continue;
13
14            for(auto &nxt : adj[node]){
15                int nxtNode = nxt.first;
16                int cst = nxt.second;
17
18                if(cst < limit) continue;
19
20                if(nxtNode != n-1 && !online[nxtNode]) continue;
21
22                dist[nxtNode] = min(dist[nxtNode], dist[node] + cst);
23            }
24        }
25
26        return dist[n-1] <= k;
27    }
28
29    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
30        n = online.size();
31        unordered_map<int, vector<pair<int,int>>> adj;
32
33        vector<int> indegree(n, 0);
34
35        int low = INT_MAX;
36        int high = 0;
37
38        for(auto &e : edges){
39            int u = e[0];
40            int v = e[1];
41            int cst = e[2];
42
43            adj[u].push_back({v, cst});
44            indegree[v]++;
45
46            low = min(low, cst);
47            high = max(high, cst);
48        }
49
50        queue<int> q;
51        vector<int> topoSort;
52
53        for(int i=0;i<n;i++){
54            if(indegree[i] == 0){
55                q.push(i);
56            }
57        }
58
59        while(!q.empty()){
60            int node = q.front();
61            q.pop();
62
63            topoSort.push_back(node);
64
65            for(auto &ngbr : adj[node]){
66                int nxtNode = ngbr.first;
67
68                indegree[nxtNode]--;
69
70                if(indegree[nxtNode] == 0){
71                    q.push(nxtNode);
72                }
73            }
74        }
75
76        int res = -1;
77
78        while(low <= high){
79            int mid = low + (high - low)/2;
80
81            if(find(mid, adj, online, topoSort, k)){
82                res = mid;
83                low = mid + 1;
84            }
85            else{
86                high = mid - 1;
87            }
88        }
89
90        return res;
91    }
92};