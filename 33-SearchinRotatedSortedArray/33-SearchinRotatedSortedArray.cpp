// Last updated: 3/16/2026, 4:41:49 PM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        for(int i = 0;i<nums.size();i++)
5        {
6            if(nums[i]==target)
7            {
8                return i;
9            }
10        }
11        return -1;
12    }
13};