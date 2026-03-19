// Last updated: 3/19/2026, 7:36:35 PM
1class Solution {
2public:
3    bool isAnagram(string s, string t) {
4        // In O(N) using frequency method
5        if(s.size()!=t.size())
6        {
7            return false;
8        }
9          vector<int> count(26,0);
10        for(int i = 0;i<s.size();i++)
11        {
12            count[s[i]-'a']++;
13            count[t[i]-'a']--;
14        }
15      
16        for(int i = 0;i<26;i++)
17        {
18            if(count[i]!=0) return false;
19        }
20
21        return true;
22    }
23};