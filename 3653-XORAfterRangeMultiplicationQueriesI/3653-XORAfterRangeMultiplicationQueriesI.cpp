// Last updated: 4/8/2026, 8:13:00 PM
1class Solution {
2public:
3    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
4        const int MOD = 1e9 + 7;
5        
6        for (int i=0;i<queries.size();i++) {
7            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
8            
9            for (int idx = l; idx <= r; idx += k) {
10                nums[idx] = (1LL * nums[idx] * v) % MOD;
11            }
12        }
13        
14        int ans = 0;
15        for (int i=0;i<nums.size();i++) {
16            ans ^= nums[i];
17        }
18        
19        return ans;
20    }
21};