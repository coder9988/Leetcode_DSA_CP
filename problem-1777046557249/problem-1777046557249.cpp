// Last updated: 4/24/2026, 9:32:37 PM
1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        int left = 0, right = 0, blanks = 0;
5
6        for (char c : moves) {
7            if (c == 'L') left++;
8            else if (c == 'R') right++;
9            else blanks++;
10        }
11
12        return abs(left - right) + blanks;
13    }
14};