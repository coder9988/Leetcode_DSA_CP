// Last updated: 3/31/2026, 10:09:32 PM
1class Solution {
2public:
3    string generateString(string str1, string str2) {
4        int n = str1.size(), m = str2.size();
5        string s(n + m - 1, 'a');
6        vector<int> fixed(n + m - 1, 0);
7        for (int i = 0; i < n; i++) {
8            if (str1[i] == 'T') {
9                for (int j = i; j < i + m; j++) {
10                    if (fixed[j] && s[j] != str2[j - i]) {
11                        return "";
12                    } else {
13                        s[j] = str2[j - i];
14                        fixed[j] = 1;
15                    }
16                }
17            }
18        }
19
20        for (int i = 0; i < n; i++) {
21            if (str1[i] == 'F') {
22                bool flag = false;
23                int idx = -1;
24                for (int j = i + m - 1; j >= i; j--) {
25                    if (str2[j - i] != s[j]) {
26                        flag = true;
27                    }
28                    if (idx == -1 && !fixed[j]) {
29                        idx = j;
30                    }
31                }
32                if (flag) {
33                    continue;
34                } else if (idx != -1) {
35                    s[idx] = 'b';
36                } else {
37                    return "";
38                }
39            }
40        }
41        return s;
42    }
43};