// Last updated: 5/3/2026, 1:27:15 PM
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        for(int i = 0;i<s.size();i++)
5        {
6            if(s==goal)
7            {
8                return true;
9            }
10            char ch = s[0];
11            s.erase(0,1);
12            s+=ch;
13        }
14        return false;
15    }
16};