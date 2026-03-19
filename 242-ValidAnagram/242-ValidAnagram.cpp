// Last updated: 3/19/2026, 7:28:07 PM
1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        sort(s.begin(),s.end());
5        sort(t.begin(),t.end());
6        // map<char,int> mp1;
7        // map<char,int> mp2;
8        if(s.size()!=t.size())
9        {
10            return false;
11        }
12        bool res = false;
13        for(int i = 0;i<s.size();i++)
14        {
15            if(s[i]==t[i])
16            {
17                res = true;
18            }
19            else
20            {
21                return false;
22            }
23            cout<<res;
24        }
25        return res;
26    }
27};