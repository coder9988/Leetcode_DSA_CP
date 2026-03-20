// Last updated: 3/20/2026, 11:48:35 PM
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_map<int,int> mp;
5        for(int i=0;i<nums.size();i++)
6        {
7            mp[nums[i]]++;
8            if(mp[nums[i]]>1)
9            {
10                return true;
11            }
12        }
13        return false;
14    }
15};