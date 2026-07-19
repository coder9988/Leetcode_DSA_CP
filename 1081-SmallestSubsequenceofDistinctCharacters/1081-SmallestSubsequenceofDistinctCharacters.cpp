// Last updated: 7/20/2026, 1:16:35 AM
1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        vector<int> last(26);
5
6        // Last occurrence of every character
7        for (int i = 0; i < s.size(); i++)
8            last[s[i] - 'a'] = i;
9
10        vector<bool> inStack(26, false);
11        string st;
12
13        for (int i = 0; i < s.size(); i++) {
14            char ch = s[i];
15
16            // if already included then skip
17            if (inStack[ch - 'a'])
18                continue;
19
20            // remove larger characters from stack if they appear in future
21            while (!st.empty() && st.back() > ch &&last[st.back() - 'a'] > i) {
22                inStack[st.back() - 'a'] = false;
23                st.pop_back();
24            }
25
26            st.push_back(ch);
27            inStack[ch - 'a'] = true;
28        }
29
30        return st;
31    }
32};