// Last updated: 8/2/2026, 1:05:52 AM
1class Solution {
2public:
3    bool predictTheWinner(vector<int>& nums) {
4        int n = nums.size();
5        
6        if (n % 2 == 0) return true; 
7        
8        vector<int> dp(nums);
9        for (int i = n - 2; i >= 0; --i) {
10            for (int j = i + 1; j < n; ++j) {
11                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
12            }
13        }
14        return dp[n - 1] >= 0;
15    }
16};