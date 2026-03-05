// Last updated: 3/5/2026, 1:45:56 PM
1class Solution {
2public:
3    int minOperations(string s) {
4        int n, c = 0, j = 0;
5        for(n = 0; n < s.size(); n++, j ^= 1) {
6            if(s[n] - '0' == j) c++;
7        }
8        return min(c, n - c);
9    }
10};