// Last updated: 6/21/2026, 7:14:59 PM
1class Solution {
2public:
3    bool isPalindrome(string s) {
4        s.erase(remove_if(s.begin(),s.end(),[](char ch)
5        {
6        return !isalnum(ch);
7        }),s.end());
8        transform(s.begin(), s.end(), s.begin(),
9          [](char c)
10          {
11              return tolower(c);
12          });
13        cout<<s;
14        int i = 0;int j = s.size()-1;
15        while(i<j)
16        {
17            if(s[i] != s[j])
18            {
19                return false;
20            }
21            i++;j--;
22        }
23        return true;
24    }
25};