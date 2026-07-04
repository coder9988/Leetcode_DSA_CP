// Last updated: 7/5/2026, 1:40:50 AM
1//translated using AI
2class Solution {
3public:
4    vector<int> parent, rank;
5
6    int minScore(int n, vector<vector<int>>& roads) {
7        parent.resize(n + 1);
8        rank.assign(n + 1, 0);
9
10        for (int i = 1; i <= n; i++)
11            parent[i] = i;
12
13        for (auto &road : roads)
14            unite(road[0], road[1]);
15
16        int root = find(1);
17        int ans = INT_MAX;
18
19        for (auto &road : roads) {
20            if (find(road[0]) == root)
21                ans = min(ans, road[2]);
22        }
23
24        return ans;
25    }
26
27    int find(int x) {
28        if (parent[x] != x)
29            parent[x] = find(parent[x]);
30        return parent[x];
31    }
32
33    void unite(int a, int b) {
34        int pa = find(a);
35        int pb = find(b);
36
37        if (pa == pb) return;
38
39        if (rank[pa] < rank[pb])
40            parent[pa] = pb;
41        else if (rank[pa] > rank[pb])
42            parent[pb] = pa;
43        else {
44            parent[pb] = pa;
45            rank[pa]++;
46        }
47    }
48};