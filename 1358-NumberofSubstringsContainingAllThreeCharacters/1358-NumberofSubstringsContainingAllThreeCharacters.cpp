// Last updated: 7/1/2026, 12:21:05 AM
1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        int res = 0;
5        int p[3] = {-1, -1, -1};
6
7        for (int i = 0; i < s.length(); i++) {
8            p[(s[i] & 31) - 1] = i;
9            res += min({p[0], p[1], p[2]}) + 1;
10        }
11
12        return res;
13    }
14};