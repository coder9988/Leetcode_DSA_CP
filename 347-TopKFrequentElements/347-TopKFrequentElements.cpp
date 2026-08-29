// Last updated: 8/29/2026, 7:02:50 PM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        map<int,int> mp;
5        for(int i:nums)
6        {
7            mp[i]++;
8        }
9        vector<pair<int,int>> pr;
10        for(auto &i:mp)
11        {
12            pr.push_back({i.first,i.second});
13        }
14        sort(pr.begin(),pr.end(),[](auto &a,auto &b)
15        {
16            if(a.second == b.second)
17            {
18                return a.first<b.first;
19            }
20            return a.second>b.second;
21        });
22        vector<int> ans;
23        for(int i = 0;i<k;i++)
24        {
25            ans.push_back(pr[i].first);
26        }
27        return ans;
28    }
29};