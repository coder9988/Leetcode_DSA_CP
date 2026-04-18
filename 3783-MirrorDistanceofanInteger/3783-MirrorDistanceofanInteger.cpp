// Last updated: 4/18/2026, 10:27:30 PM
1class Solution {
2public:
3    int mirrorDistance(int n) {
4        string s = to_string(n);
5        reverse(s.begin(),s.end());
6        int flip = stoi(s);
7        return abs(n-flip);
8    }
9};