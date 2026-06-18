// Last updated: 6/18/2026, 5:06:26 PM
1class Solution {
2public:
3    vector<int> topKFrequent(vector<int>& nums, int k) {
4        vector<pair<int,int>> v;
5        map<int,int> freq;
6        vector<int> res;
7        for(int i:nums)
8        {
9            freq[i]++;
10        }
11        for(auto it:freq)
12        {
13            v.push_back({it.second,it.first});
14        } 
15        sort(v.begin(),v.end(),greater<pair<int,int>>());
16        for(int i =0;i<k;i++)
17        {
18            res.push_back(v[i].second);
19        }
20        return res;
21    }
22};