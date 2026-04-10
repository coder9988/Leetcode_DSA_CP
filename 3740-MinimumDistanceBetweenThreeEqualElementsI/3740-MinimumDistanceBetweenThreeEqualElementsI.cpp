// Last updated: 4/10/2026, 11:46:49 PM
1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        int n = nums.size() ;
5        if (n <= 2) return -1 ;
6        int ans = INT_MAX ;
7        for (int i = 0; i < n; i++) {
8            for (int j = i+1; j < n; j++)
9                if (nums[i] == nums[j])
10                for (int k = j+1; k < n; k++)
11                    if (nums[j] == nums[k])
12                    ans = min(ans, 2*(k-i)) ;
13        }
14        if (ans == INT_MAX) return -1 ;
15        else return ans ;
16    }
17};