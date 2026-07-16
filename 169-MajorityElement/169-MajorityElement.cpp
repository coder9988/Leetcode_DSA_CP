// Last updated: 7/16/2026, 3:03:51 PM
1class Solution {
2public:
3    int majorityElement(vector<int>& nums) {
4        unordered_map<int, int> mp;
5        for (int i : nums) {
6            mp[i]++;
7            if (mp[i] > nums.size() / 2) {
8                return i;
9            }
10            
11        }
12        return 0;
13    }
14};