// Last updated: 7/6/2026, 1:43:22 AM
1class Solution {
2public:
3    vector<int> pathsWithMaxScore(vector<string>& board) {
4        const int MOD = 1000000007;
5        int n = board.size();
6
7        vector<int> nextScore(n + 1, -1);
8        vector<int> nextWays(n + 1, 0);
9
10        for (int i = n - 1; i >= 0; --i) {
11            vector<int> currScore(n + 1, -1);
12            vector<int> currWays(n + 1, 0);
13
14            for (int j = n - 1; j >= 0; --j) {
15                char cell = board[i][j];
16
17                if (cell == 'X') {
18                    continue;
19                }
20
21                if (cell == 'S') {
22                    currScore[j] = 0;
23                    currWays[j] = 1;
24                    continue;
25                }
26
27                int best = max({
28                    nextScore[j],
29                    currScore[j + 1],
30                    nextScore[j + 1]
31                });
32
33                if (best == -1) {
34                    continue;
35                }
36
37                long long ways = 0;
38
39                if (nextScore[j] == best) {
40                    ways += nextWays[j];
41                }
42                if (currScore[j + 1] == best) {
43                    ways += currWays[j + 1];
44                }
45                if (nextScore[j + 1] == best) {
46                    ways += nextWays[j + 1];
47                }
48
49                int value = (cell == 'E') ? 0 : cell - '0';
50
51                currScore[j] = best + value;
52                currWays[j] = ways % MOD;
53            }
54
55            nextScore = move(currScore);
56            nextWays = move(currWays);
57        }
58
59        if (nextScore[0] == -1) {
60            return {0, 0};
61        }
62
63        return {nextScore[0], nextWays[0]};
64    }
65};