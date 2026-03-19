// Last updated: 3/19/2026, 7:31:16 PM
1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4                if(s.size()!=t.size())
5        {
6            return false;
7        }
8        sort(s.begin(),s.end());
9        sort(t.begin(),t.end());
10
11        bool res = true;
12        for(int i = 0;i<s.size();i++)
13        {
14            if(s[i]!=t[i])
15            {
16             return false;
17            }
18   
19        }
20        return res;
21    }
22};