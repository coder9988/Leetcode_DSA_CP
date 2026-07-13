// Last updated: 7/13/2026, 11:52:30 PM
1class Solution {
2public:
3    inline static int q[45];
4    inline static bool init = []() {
5        int n = 0;
6        for (int i = 1; i < 10; i++)
7            q[n++] = i;
8
9        for (int i = 0; i < n; i++) {
10            int d = q[i] % 10;
11            if (d < 9) q[n++] = q[i] * 10 + d + 1;
12        }
13
14        return 0;
15    }();
16
17    vector<int> sequentialDigits(int low, int high) {
18        vector<int> res;
19
20        for (auto& x : q)
21            if (x >= low && x <= high)
22                res.push_back(x);
23
24        return res;
25    }
26};