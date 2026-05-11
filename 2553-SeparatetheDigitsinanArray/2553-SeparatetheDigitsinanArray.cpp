// Last updated: 5/11/2026, 11:13:40 PM
1class Solution {
2public:
3    vector<int> separateDigits(vector<int>& nums) {
4        vector<int> res;
5        for(int i : nums){
6            string s = to_string(i);
7            for(char c:s) res.push_back(c-'0');
8        }
9        return res;
10    }
11};