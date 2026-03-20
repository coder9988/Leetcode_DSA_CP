// Last updated: 3/21/2026, 12:46:25 AM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        unordered_map<int,int> mp;
5        for(int i = 0;i<nums.size();i++)
6        {
7            int need = target - nums[i];
8            if(mp.count(need))
9            {
10                return {mp[need],i};
11            }
12            mp[nums[i]] = i;
13        }
14        return {};;
15    }
16};