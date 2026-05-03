// Last updated: 5/3/2026, 1:24:37 PM
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        int i = 0;
5        int n = s.size()-1;
6        if(s.size()==1)
7        {
8            return (s==goal)?true:false;
9        }
10        while(i<n)
11        {
12            if(s==goal)
13            {
14                return true;
15            }
16            for(int j = 0;j<n;j++)
17            {
18                char ch = s[0];
19                s.erase(0,1);
20                s+=ch;
21                            if(s==goal)
22            {
23                return true;
24            }
25            }
26            i++;
27        }
28        return false;
29    }
30};