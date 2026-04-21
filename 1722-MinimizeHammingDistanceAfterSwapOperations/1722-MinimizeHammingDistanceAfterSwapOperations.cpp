// Last updated: 4/21/2026, 8:52:01 PM
1constexpr int N=1e5+1;
2int Rt[N], Rk[N]; 
3int freq[N];
4class UnionFind {
5public:
6    UnionFind(int n){
7        iota(Rt, Rt+n, 0);
8        fill(Rk, Rk+n, 0);
9    }
10    int Find(int x) {
11        // compress path
12        return (x == Rt[x])?x:Rt[x]=Find(Rt[x]);
13    }
14    bool Union(int x, int y) {
15        x=Find(x), y=Find(y);
16        if (x==y) return 0;
17        if (Rk[x]>Rk[y]) swap(x, y);
18        Rt[x]=y;
19        if (Rk[x]==Rk[y]) Rk[y]++;
20        return 1;
21    }
22};
23
24class Solution {
25public:
26    static int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
27        const int n=source.size();
28        UnionFind G(n);
29        
30        for(auto& sw : allowedSwaps)
31            G.Union(sw[0], sw[1]);
32
33        // Group indices in the same component
34        vector<vector<int>> components(n);
35        for(int i=0; i<n; i++)
36            components[G.Find(i)].push_back(i);
37
38        int match=0;
39        
40        // Process each component
41        for(int i=0;i<n; i++) {
42            if (components[i].empty()) continue;
43
44            // Count freq of source
45            for(int idx : components[i])
46                freq[source[idx]]++;
47
48            // Check how many target values in this component
49            for(int idx : components[i]) {
50                if (freq[target[idx]]>0) {
51                    freq[target[idx]]--;
52                    match++;
53                }
54            }
55
56            // reset freq for the next component
57            for(int idx : components[i]) 
58                freq[source[idx]]=0; 
59        }
60        return n-match;
61    }
62};