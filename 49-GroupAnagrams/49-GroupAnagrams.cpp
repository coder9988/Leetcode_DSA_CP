// Last updated: 6/13/2026, 10:56:11 PM
1class Solution {
2public:
3    vector<vector<string>> groupAnagrams(vector<string>& strs) {
4         unordered_map<string,vector<string>> mp;
5         vector<vector<string>> res;
6         for(auto it:strs)
7         {
8           string key = it;
9           sort(key.begin(),key.end());
10           mp[key].push_back(it);
11         }
12         for(auto v:mp)
13         {
14            res.push_back(v.second);
15         }
16         return res;
17    }
18};