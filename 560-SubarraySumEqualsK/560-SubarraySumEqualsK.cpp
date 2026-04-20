// Last updated: 4/20/2026, 5:18:07 PM
1class Solution {
2public:
3    int subarraySum(vector<int>& nums, int k) {
4        unordered_map<int, int> mp;
5        int sum = 0;
6        int c = 0;
7        mp.insert({0,1});
8        for (int i = 0; i < nums.size(); i++) {
9            sum += nums[i];
10            if (mp.find(sum - k) != mp.end()) {
11                c += mp[sum - k];
12            }
13            mp[sum]++;
14        }
15        return c;
16    }
17};