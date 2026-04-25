// Last updated: 4/25/2026, 6:43:12 PM
1class Solution {
2public:
3    int maxDistance(int side, vector<vector<int>>& points, int k) {
4        vector<long long> res;
5        for (auto& p : points) {
6            int x = p[0], y = p[1];
7            if (x == 0) res.push_back(y);
8            else if (y == side) 
9                res.push_back((long long)side + x);
10            else if (x == side) 
11                res.push_back((long long)side * 3 - y);
12            else res.push_back((long long)side * 4 - x);
13        }
14        sort(res.begin(), res.end());
15
16        auto check = [&](int n) {
17            int m = res.size();
18            vector<int> idx(k);
19            long long curr = res[0];
20            idx[0] = 0;
21            for (int i = 1; i < k; i++) {
22                auto it = lower_bound(res.begin(), res.end(), curr + n);
23                if (it == res.end()) 
24                    return false;
25                idx[i] = distance(res.begin(), it);
26                curr = *it;
27            }
28            if (res[idx[k - 1]] - res[0] <= (long long)side * 4 - n) 
29                return true;
30
31            for (idx[0] = 1; idx[0] < idx[1]; idx[0]++) {
32                for (int j = 1; j < k; j++) {
33                    while (idx[j] < m && res[idx[j]] < res[idx[j - 1]] + n) {
34                        idx[j]++;
35                    }
36                    if (idx[j] == m) 
37                        return false;
38                }
39                if (res[idx[k - 1]] - res[idx[0]] <= (long long)side * 4 - n) 
40                    return true;
41            }
42            return false;
43        };
44
45        int left = 1;
46        int right = (1LL * side * 4) / k + 1;
47        while (left + 1 < right) {
48            int mid = left + (right - left) / 2;
49            if (check(mid)) 
50                left = mid;
51            else right = mid;
52        }
53        return left;
54    }
55};