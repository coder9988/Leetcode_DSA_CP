// Last updated: 7/22/2026, 12:32:46 AM
1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        int ones = 0;
5        for(char c : s)
6            if(c == '1')
7                ones++;
8
9        s = "1" + s + "1";
10
11        int n = s.size();
12        int i = 0;
13
14        int ans = ones;
15
16        // Skip first 1's
17        while(i < n && s[i] == '1')
18            i++;
19
20        // Read first 0-block
21        int c10 = 0;
22        while(i < n && s[i] == '0'){
23            c10++;
24            i++;
25        }
26
27        while(i < n){
28
29            // Read middle 1-block
30            int c11 = 0;
31            while(i < n && s[i] == '1'){
32                c11++;
33                i++;
34            }
35
36            if(c11 == 0)
37                break;
38
39            // Read right 0-block
40            int c20 = 0;
41            while(i < n && s[i] == '0'){
42                c20++;
43                i++;
44            }
45
46            if(c20 == 0)
47                break;
48
49            ans = max(ans, ones + c10 + c20);
50
51            // Slide the window
52            c10 = c20;
53        }
54
55        return ans;
56    }
57};