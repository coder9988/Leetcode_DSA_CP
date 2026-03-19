// Last updated: 3/19/2026, 7:30:14 PM
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
11        bool res = false;
12        for(int i = 0;i<s.size();i++)
13        {
14            if(s[i]==t[i])
15            {
16                res = true;
17            }
18            else
19            {
20                return false;
21            }
22            cout<<res;
23        }
24        return res;
25    }
26};