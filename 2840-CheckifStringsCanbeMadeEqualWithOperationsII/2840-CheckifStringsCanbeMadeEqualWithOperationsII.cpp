// Last updated: 3/30/2026, 11:04:45 PM
1class Solution {
2public:
3    bool checkStrings(string s1, string s2) {
4        int freq[52] = {};
5
6        for (int i = 0; i < s1.length(); i++) {
7            int off = (i & 1) * 26;
8            freq[s1[i] - 'a' + off]++;
9            freq[s2[i] - 'a' + off]--;
10        }
11
12        for (int i = 0; i < 52; i++)
13            if (freq[i] != 0) return false;
14
15        return true;
16    }
17};