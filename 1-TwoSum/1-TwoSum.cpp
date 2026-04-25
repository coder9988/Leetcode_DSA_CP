// Last updated: 4/25/2026, 7:38:17 PM
1class Solution {
2public:
3    vector<int> twoSum(vector<int>& nums, int target) {
4        unordered_map<int,int> mp;
5        int need = 0;
6        for(int i = 0;i<nums.size();i++)
7        {
8            need = target - nums[i];
9            if(mp.count(need))
10            {
11                return {mp[need],i};
12            }
13            mp[nums[i]] = i;
14            need = 0;
15        }
16        return {};
17    }
18};