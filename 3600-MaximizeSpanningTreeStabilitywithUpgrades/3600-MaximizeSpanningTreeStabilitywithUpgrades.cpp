// Last updated: 3/12/2026, 8:13:02 PM
1struct DSU {
2    vector<int> p, sz;
3    int c;
4    DSU(int n) {
5        p.resize(n);
6        sz.resize(n, 1);
7        iota(p.begin(), p.end(), 0);
8        c = n;
9    }
10    int f(int i) {
11        if (p[i] == i) return i;
12        return p[i] = f(p[i]);
13    }
14    bool u(int i, int j) {
15        int x = f(i);
16        int y = f(j);
17        if (x != y) {
18            if (sz[x] < sz[y]) swap(x, y);
19            p[y] = x;
20            sz[x] += sz[y];
21            c--;
22            return true;
23        }
24        return false;
25    }
26};
27class Solution {
28public:
29    int maxStability(int n, vector<vector<int>>& edges, int k) {
30        DSU g(n);
31        for (auto &e : edges) g.u(e[0], e[1]);
32        if (g.c > 1) return -1;
33        DSU b(n);
34        int m = 2e9; 
35        vector<pair<int, pair<int, int>>> o;
36        for (auto &e : edges) {
37            if (e[3] == 1) {
38                m = min(m, e[2]);
39                if (!b.u(e[0], e[1])) return -1;
40            } else o.push_back({e[2], {e[0], e[1]}});
41            
42        }
43        auto isOk = [&](int t, DSU d) {
44            for (auto &e : o) {
45                if (e.first >= t) {
46                    d.u(e.second.first, e.second.second);
47                }
48            }
49            int u = 0;
50            for (auto &e : o) {
51                if (e.first < t && 2 * e.first >= t) {
52                    if (d.u(e.second.first, e.second.second)) {
53                        u++;
54                    }
55                }
56            }
57            return d.c == 1 && u <= k;
58        };
59        int l = -1;
60        int h = min(200000, m) + 1; 
61        while (h - l > 1) {
62            int mid = l + (h - l) / 2;
63            if (isOk(mid, b)) l = mid;
64            else h = mid;
65        }
66        return l;
67    }
68};