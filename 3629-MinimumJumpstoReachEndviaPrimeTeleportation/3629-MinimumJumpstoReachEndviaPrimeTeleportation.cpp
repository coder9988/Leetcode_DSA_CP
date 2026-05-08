// Last updated: 5/8/2026, 11:34:17 PM
1class Solution {
2public:
3    
4    bool isPrime(int x) {
5        if (x < 2) return false;
6
7        for (int i = 2; i * i <= x; i++) {
8            if (x % i == 0) return false;
9        }
10
11        return true;
12    }
13
14    vector<int> getPrimeFactors(int x) {
15        vector<int> factors;
16
17        for (int p = 2; p * p <= x; p++) {
18            if (x % p == 0) {
19                factors.push_back(p);
20
21                while (x % p == 0) {
22                    x /= p;
23                }
24            }
25        }
26
27        if (x > 1) factors.push_back(x);
28
29        return factors;
30    }
31
32    int minJumps(vector<int>& nums) {
33
34        int n = nums.size();
35
36        unordered_map<int, vector<int>> mp;
37
38        for (int i = 0; i < n; i++) {
39
40            vector<int> factors = getPrimeFactors(nums[i]);
41
42            for (int f : factors) {
43                mp[f].push_back(i);
44            }
45        }
46
47        queue<int> q;
48        vector<int> vis(n, 0);
49
50        q.push(0);
51        vis[0] = 1;
52
53        int steps = 0;
54
55        while (!q.empty()) {
56
57            int sz = q.size();
58
59            while (sz--) {
60
61                int idx = q.front();
62                q.pop();
63
64                if (idx == n - 1) return steps;
65
66                // left
67                if (idx - 1 >= 0 && !vis[idx - 1]) {
68                    vis[idx - 1] = 1;
69                    q.push(idx - 1);
70                }
71
72                // right
73                if (idx + 1 < n && !vis[idx + 1]) {
74                    vis[idx + 1] = 1;
75                    q.push(idx + 1);
76                }
77
78                // teleport
79                if (isPrime(nums[idx])) {
80
81                    int p = nums[idx];
82
83                    for (int nextIdx : mp[p]) {
84
85                        if (!vis[nextIdx]) {
86                            vis[nextIdx] = 1;
87                            q.push(nextIdx);
88                        }
89                    }
90
91                    mp[p].clear();
92                }
93            }
94
95            steps++;
96        }
97
98        return -1;
99    }
100};