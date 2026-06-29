// Last updated: 6/30/2026, 12:17:27 AM
1class Solution {
2public:
3    int numOfStrings(vector<string>& patterns, string word) {
4        int c = 0;
5        for(string s:patterns)
6        {
7            if(word.contains(s))
8            {
9                c+=1;
10            }
11        }
12        return c;
13    }
14};