// Last updated: 4/14/2026, 11:53:04 PM
1class Solution {
2public:
3    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
4        sort(robot.begin(), robot.end());
5        sort(factory.begin(), factory.end());
6
7        int n = robot.size();
8        int m = factory.size();
9
10        const long long INF = 1e18;
11        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));
12
13        for (int j = 0; j <= m; j++)
14            dp[0][j] = 0;
15
16        for (int j = 1; j <= m; j++) {
17            int pos = factory[j-1][0];
18            int limit = factory[j-1][1];
19
20            for (int i = 0; i <= n; i++) {
21                dp[i][j] = dp[i][j-1]; // skip factory
22
23                long long dist = 0;
24                for (int k = 1; k <= limit && i - k >= 0; k++) {
25                    dist += abs(robot[i-k] - pos);
26                    dp[i][j] = min(dp[i][j], dp[i-k][j-1] + dist);
27                }
28            }
29        }
30
31        return dp[n][m];
32    }
33};