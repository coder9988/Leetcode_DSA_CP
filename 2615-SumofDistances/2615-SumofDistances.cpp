// Last updated: 4/23/2026, 2:56:06 PM
1class Solution {
2public:
3    vector<long long> distance(vector<int>& nums) {
4        int n = nums.size();
5        vector<long long> ans(n);
6
7        unordered_map<int, vector<int>> mp;
8
9        for(int i = 0; i < n; i++)
10            mp[nums[i]].push_back(i);
11
12        for(auto &it : mp){
13            auto &pos = it.second;
14
15            long long sum = 0;
16            for(int x : pos) sum += x;
17
18            long long leftSum = 0;
19            int m = pos.size();
20
21            for(int i = 0; i < m; i++){
22                long long rightSum = sum - leftSum - pos[i];
23
24                long long left  = 1LL * pos[i] * i - leftSum;
25                long long right = rightSum - 1LL * pos[i] * (m-i-1);
26
27                ans[pos[i]] = left + right;
28
29                leftSum += pos[i];
30            }
31        }
32
33        return ans;
34    }
35};