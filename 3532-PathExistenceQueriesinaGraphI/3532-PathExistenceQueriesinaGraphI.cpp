// Last updated: 7/9/2026, 11:11:41 PM
1class Solution {
2public:
3    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
4                                      vector<vector<int>>& queries) {
5        vector<int> cmp(n);
6
7        for (int i = 1; i < n; i++) {
8            cmp[i] = cmp[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
9        }
10
11        vector<bool> res;
12
13        for (const auto &q : queries) {
14            res.push_back(cmp[q[0]] == cmp[q[1]]);
15        }
16
17        return res;
18    }
19};