// Last updated: 9/14/2026, 10:49:51 AM
1class Solution {
2public:
3    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
4        stack<int>s;
5        vector<int> ans;
6        unordered_map<int,int> mp;
7        for(int i =0;i<nums2.size();i++)
8        {
9            while(!s.empty() && s.top()<nums2[i])
10            {
11                mp[s.top()] = nums2[i];
12                s.pop();
13            }
14            s.push(nums2[i]);
15        }
16        for(int i:nums1)
17        {
18            if(mp.find(i)!=mp.end())
19            {
20                ans.push_back(mp[i]);
21            }
22            else
23            {
24                ans.push_back(-1);
25            }
26        }
27        return ans;
28    }
29};