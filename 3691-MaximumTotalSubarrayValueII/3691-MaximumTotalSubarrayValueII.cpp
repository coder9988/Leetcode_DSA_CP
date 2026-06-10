// Last updated: 6/11/2026, 3:47:29 AM
1class Solution {
2public:
3    vector<vector<int>> stMax, stMin;
4    vector<int> lg;
5
6    long long getValue(int l, int r) {
7
8        int len = r - l + 1;
9        int p = lg[len];
10
11        int mx = max(
12            stMax[p][l],
13            stMax[p][r - (1 << p) + 1]
14        );
15
16        int mn = min(
17            stMin[p][l],
18            stMin[p][r - (1 << p) + 1]
19        );
20
21        return 1LL * mx - mn;
22    }
23
24    long long maxTotalValue(vector<int>& nums, int k) {
25        int n = nums.size();
26
27        // Precompute logs
28        //lg[i] stores the exponent of the largest power of 2 that is ≤ i.
29        lg.resize(n + 1);
30        for (int i = 2; i <= n; i++) {
31            lg[i] = lg[i / 2] + 1;
32        }
33
34        int LOG = lg[n] + 1; //total layers in sparse table
35
36        stMax.assign(LOG, vector<int>(n));
37        stMin.assign(LOG, vector<int>(n));
38
39        // Level 0 of sparse table
40        for (int i = 0; i < n; i++) {
41            stMax[0][i] = nums[i];
42            stMin[0][i] = nums[i];
43        }
44
45        // Build Sparse Tables
46        for (int j = 1; j < LOG; j++) {
47            for (int i = 0; i + (1 << j) <= n; i++) {
48
49                stMax[j][i] = max(
50                    stMax[j - 1][i],
51                    stMax[j - 1][i + (1 << (j - 1))]
52                );
53
54                stMin[j][i] = min(
55                    stMin[j - 1][i],
56                    stMin[j - 1][i + (1 << (j - 1))]
57                );
58            }
59        }
60
61        using T = tuple<long long, int, int>;
62        priority_queue<T> pq;
63
64        // For every starting index, begin with the interval [l, n-1]
65        for (int l = 0; l < n; l++) {
66            pq.push({getValue(l, n - 1), l, n - 1});
67        }
68
69        long long ans = 0;
70
71        while (k--) {
72            auto [val, l, r] = pq.top();
73            pq.pop();
74
75            ans += val;
76
77            if (r > l) {
78                pq.push({getValue(l, r - 1), l, r - 1});
79            }
80        }
81
82        return ans;
83    }
84};