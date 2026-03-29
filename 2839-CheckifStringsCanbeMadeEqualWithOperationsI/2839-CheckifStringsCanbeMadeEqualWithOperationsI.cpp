// Last updated: 3/29/2026, 11:22:42 PM
1class Solution {
2public:
3    bool canBeEqual(string s1, string s2) {
4        bool s02=s1[0]==s2[2] && s1[2]==s2[0];
5        bool b02=s1[0]==s2[0] && s1[2]==s2[2];
6        bool s13=s1[1]==s2[3] && s1[3]==s2[1];
7        bool b13=s1[1]==s2[1] && s1[3]==s2[3];
8        return ((s02 ||b02)&&(s13 || b13));
9    }
10};