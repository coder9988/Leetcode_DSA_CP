// Last updated: 4/25/2026, 8:37:50 PM
1class Solution {
2public:
3    int findContentChildren(vector<int>& g, vector<int>& s) {
4        sort(g.begin(),g.end());
5         sort(s.begin(),s.end());
6         if(s.empty() || g.empty())
7         {
8            return 0;
9         }
10         int i = 0;int j = 0;
11         int c= 0;
12         while(i<=g.size()-1 && j<=s.size()-1)
13         {
14            if(s[j]>=g[i])
15            {
16                i+=1;
17                // j+=1;
18                c+=1;
19            }
20            j+=1;
21         }
22         return i;
23    }
24};