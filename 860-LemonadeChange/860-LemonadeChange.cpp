// Last updated: 8/31/2026, 11:20:12 AM
1class Solution {
2public:
3    int minimumSum(int num) {
4        string s = to_string(num);
5        sort(s.begin(),s.end());
6        return stoi(s.substr(0, 1) + s.substr(2, 1)) +
7           stoi(s.substr(1, 1) + s.substr(3, 1));
8    }
9};