// Last updated: 5/5/2026, 10:07:48 PM
1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        int n = nums.size();
5        int total = accumulate(nums.begin(), nums.end(), 0);
6        
7        int F = 0;
8        for (int i = 0; i < n; i++) {
9            F += i * nums[i];
10        }
11
12        int ans = F;
13
14        for (int k = 1; k < n; k++) {
15            F = F + total - n * nums[n - k];
16            ans = max(ans, F);
17        }
18
19        return ans;
20    }
21};