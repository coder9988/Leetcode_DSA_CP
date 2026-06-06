// Last updated: 6/7/2026, 2:44:44 AM
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_map<int,int> freq;
5        for(int i:nums)
6        {
7            freq[i]++;
8            if(freq[i]>1)
9            {
10                return true;
11            }
12        }
13        return false;
14    }
15};