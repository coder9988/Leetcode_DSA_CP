// Last updated: 6/5/2026, 11:44:44 PM
1class Solution {
2public:
3    struct Node {
4        long long cnt;
5        long long wav;
6    };
7
8    string s;
9    Node dp[20][2][11][11];
10    bool vis[20][2][11][11];
11
12    Node dfs(int pos, int started, int last, int secondLast, bool tight) {
13        if (pos == (int)s.size()) {
14            return {1, 0};
15        }
16
17        if (!tight && vis[pos][started][last][secondLast]) {
18            return dp[pos][started][last][secondLast];
19        }
20
21        int limit = tight ? s[pos] - '0' : 9;
22
23        Node res = {0, 0};
24
25        for (int d = 0; d <= limit; d++) {
26            bool ntight = tight && (d == limit);
27
28            if (!started && d == 0) {
29                Node nxt = dfs(pos + 1, 0, 10, 10, ntight);
30
31                res.cnt += nxt.cnt;
32                res.wav += nxt.wav;
33            } else {
34                long long add = 0;
35
36                if (started && secondLast != 10) {
37                    if ((last > secondLast && last > d) ||
38                        (last < secondLast && last < d)) {
39                        add = 1;
40                    }
41                }
42
43                int nSecondLast = started ? last : 10;
44                int nLast = d;
45
46                Node nxt = dfs(pos + 1, 1, nLast, nSecondLast, ntight);
47
48                res.cnt += nxt.cnt;
49                res.wav += nxt.wav + add * nxt.cnt;
50            }
51        }
52
53        if (!tight) {
54            vis[pos][started][last][secondLast] = true;
55            dp[pos][started][last][secondLast] = res;
56        }
57
58        return res;
59    }
60
61    long long solve(long long n) {
62        if (n < 0) return 0;
63
64        s = to_string(n);
65        memset(vis, 0, sizeof(vis));
66
67        return dfs(0, 0, 10, 10, true).wav;
68    }
69
70    long long totalWaviness(long long num1, long long num2) {
71        return solve(num2) - solve(num1 - 1);
72    }
73};