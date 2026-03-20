// Last updated: 3/21/2026, 12:58:22 AM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        int ans = 0;
5        for(int i=0;i<nums.size();i++)
6        {
7            ans ^= nums[i];
8        }
9        return ans;
10    }
11};