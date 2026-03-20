// Last updated: 3/21/2026, 12:58:07 AM
1class Solution {
2public:
3    int singleNumber(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        int ans = 0;
6        for(int i=0;i<nums.size();i++)
7        {
8            ans ^= nums[i];
9        }
10        return ans;
11    }
12};