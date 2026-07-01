// Last updated: 7/2/2026, 2:17:09 AM
1// union find class with rank
2const int N=160000;
3int Root[N], Rank[N];
4static int d[5] = {0, 1, 0, -1, 0};
5class UnionFind {
6public:
7    UnionFind(int n){
8        iota(Root, Root+n, 0);
9        memset(Rank, 0, n*sizeof(int));
10    }
11
12    int Find(int x) {
13        return (x == Root[x])? x :Root[x]=Find(Root[x]);
14    }
15
16    bool Union(int x, int y) {
17        x=Find(x), y=Find(y);
18        if (x==y) return 0;
19        if (Rank[x] > Rank[y]) swap(x, y);
20        Root[x] = y;
21        if (Rank[x] == Rank[y])
22            Rank[y]++;
23        return 1;
24    }
25    bool connected(int x, int y) { return Find(x) == Find(y); }
26};
27
28int L1[800];// heads for array version of linked lists
29int nxt[N];
30inline void insert(int L, int idx){
31    nxt[idx]=L1[L];
32    L1[L]=idx;
33}
34using int2 = pair<int, int>; //(i, j)
35int2 q[N];
36int front, back;
37class Solution {
38public:
39    inline static int to1d(int i, int j, int n) { return i*n+j; }
40
41    static int maximumSafenessFactor(vector<vector<int>>& grid) {
42        const int n = grid.size();
43        if (grid[0][0] || grid[n-1][n-1])
44            return 0; // very special case
45        front=back=0; // reset q
46        for (int i = 0; i < n; i++) {
47            for (int j = 0; j < n; j++) {
48                if (grid[i][j] == 1) {
49                    grid[i][j] = 0;
50                    q[back++]={i, j};
51                } 
52                else
53                    grid[i][j] = -1;
54            }
55        }
56        memset(L1, -1, 2*n*sizeof(int));
57        memset(nxt, -1, n*n*sizeof(int));
58
59        int dist = 0;
60        while (front<back) {
61            int qz = back-front;
62            for (int a = 0; a < qz; a++) {
63                auto [i, j] = q[front++];
64                for (int b = 0; b < 4; b++) {
65                    int r = i + d[b], c = j + d[b + 1];
66                    if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != -1)
67                        continue;
68                    grid[r][c] = dist + 1;
69                    q[back++]={r, c};
70                    insert(dist + 1, to1d(r, c, n));
71                }
72            }
73            dist++;
74        }
75
76        UnionFind G(n * n);
77        for (int dd = dist - 1; dd >= 0; dd--) {
78            if (L1[dd]==-1)
79                continue;
80            for (int idx=L1[dd]; idx!=-1; idx=nxt[idx]) {
81                auto [i, j]=div(idx, n);
82                for (int b = 0; b < 4; b++) {
83                    int r = i + d[b], c = j + d[b + 1];
84                    if (r < 0 || r >= n || c < 0 || c >= n)
85                        continue;
86                    if (grid[r][c] >= dd)
87                        G.Union(to1d(i, j, n), to1d(r, c, n));
88                }
89            }
90            if (G.connected(0, n * n - 1))
91                return dd;
92        }
93        return 0;
94    }
95};
96
97auto init = []() {
98    ios::sync_with_stdio(0);
99    cin.tie(0);
100    cout.tie(0);
101    return 'c';
102}();