// Last updated: 3/26/2026, 10:00:16 PM
1// 1d flat array version
2static const int M=1e5+1;
3static int A[M];
4static bitset<M> Seen;
5
6class Solution {
7public:
8    static bool canPartitionGrid(vector<vector<int>>& grid) {
9        const int r=grid.size(), c=grid[0].size(), N=r*c;
10        long long Tsum=0;
11        
12        Seen.reset();
13        int idx=0;
14        for(auto& row: grid){
15            memcpy(A+idx, row.data(), sizeof(int)*c);
16            idx+=c;
17        }
18
19        int xMax=0;
20        for (int i=0; i<N; i++) {
21            const int x=A[i];
22            Tsum+=x;
23            xMax=max(x, xMax);
24            
25        }
26
27        // Horizontal Cuts
28        long long top=0;
29        // First pass for Top removals
30        for (int i=0; i<r-1; i++) {
31            for (int j=0; j<c; j++) {
32                const int x=A[i*c+j];
33                top+=x;
34                Seen[x]=1;
35            }
36            long long bot=Tsum-top;
37            if (top==bot) return 1;
38
39            long long d=top - bot;
40            if (d > 0 && d<=xMax) {
41                if (i>0 && c>1) { if (Seen[d]) return 1; }
42                else if (A[0]==d || A[(i+1)*c-1]==d) return 1;
43            }
44        }
45        Seen.reset();
46        long long bot=0;
47        // Second pass for Bottom removals
48        for (int i=r-1; i>=1; i--) {
49            for (int j=c-1; j>=0; j--) {
50                const int x=A[i*c+j];
51                bot+=x;
52                Seen[x]=1;
53            }
54            long long topS=Tsum-bot;
55            long long d=bot-topS;
56            if (d>0 &&d<=xMax) {
57                if ((r-1-i)>0 && c>1) { if (Seen[d]) return 1; }
58                else if (A[i*c]==d || A[N-1]==d) return 1;
59            }
60        }
61
62        // Vertical Cuts 
63        Seen.reset();
64        long long left=0;
65        for (int j=0; j<c-1; j++) {
66            for (int i=0; i<r; i++) {
67                const int x=A[i*c+j];
68                left+=x;
69                Seen[x]=1;
70            }
71            long long right=Tsum-left;
72            if (left==right) return 1;
73
74            long long d=left-right;
75            if (d>0 && d<=xMax) {
76                if (r>1 && j>0) { if (Seen[d]) return 1; } 
77                else if (A[0]==d || A[(r-1)*c+j]==d) return 1;
78            }
79        }
80        Seen.reset();
81        long long right=0;
82        for (int j=c-1; j>=1; j--) {
83            for (int i=0; i<r; i++) {
84                const int x=A[i*c+j];
85                right+=x;
86                Seen[x]=1;
87            }
88            long long leftS=Tsum-right;
89            long long d=right-leftS;
90            if (d>0 && d<=xMax) {
91                if (r>1 && (c-1-j)>0) { if (Seen[d]) return 1; } 
92                else if (A[j]==d || A[N-1]==d) return 1;
93            }
94        }
95        return 0;
96    }
97};
98
99auto init = []() {
100    ios::sync_with_stdio(0);
101    cin.tie(0);
102    cout.tie(0);
103    return 'c';
104}();