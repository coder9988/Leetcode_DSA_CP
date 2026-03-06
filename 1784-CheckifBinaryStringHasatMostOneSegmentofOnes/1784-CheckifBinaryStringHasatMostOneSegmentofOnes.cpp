// Last updated: 3/6/2026, 10:03:42 PM
1class Solution {
2public:
3    bool checkOnesSegment(string s) {
4        return s.find("01") == string::npos;
5    }
6};