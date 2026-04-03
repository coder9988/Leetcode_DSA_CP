// Last updated: 4/3/2026, 9:21:36 PM
1class Solution {
2public:
3    int count_walls(const vector<int>& walls, long long l, long long r) {
4        if (l > r) 
5            return 0;
6        auto it_l = lower_bound(walls.begin(), walls.end(), (int)l);
7        auto it_r = upper_bound(walls.begin(), walls.end(), (int)r);
8        return (int)distance(it_l, it_r);
9    }
10
11    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
12        int n = robots.size();
13        if (n == 0) 
14            return 0;
15
16        sort(walls.begin(), walls.end());
17
18        vector<pair<long long, int>> r_data(n);
19        for (int i = 0; i < n; ++i) {
20            r_data[i] = {robots[i], distance[i]};
21        }
22        sort(r_data.begin(), r_data.end());
23
24        vector<vector<int>> dp(n, vector<int>(2, 0));
25
26        long long INF = 2e18;
27        long long pos0 = r_data[0].first;
28        int dist0 = r_data[0].second;
29        long long next_r = (n > 1) ? r_data[1].first : INF;
30
31        dp[0][0] = count_walls(walls, pos0 - dist0, pos0);
32        dp[0][1] = count_walls(walls, pos0, min(pos0 + dist0, next_r - 1));
33
34        for (int i = 1; i < n; ++i) {
35            long long cur_p = r_data[i].first;
36            int cur_d = r_data[i].second;
37            long long pre_p = r_data[i - 1].first;
38            int pre_d = r_data[i - 1].second;
39            next_r = (i + 1 < n) ? r_data[i + 1].first : INF;
40
41            int r_gain = count_walls(walls, cur_p, min(cur_p + cur_d, next_r - 1));
42            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + r_gain;
43
44            long long l_lim = max(cur_p - cur_d, pre_p + 1);
45            int l_gain = count_walls(walls, l_lim, cur_p);
46
47            dp[i][0] = dp[i - 1][0] + l_gain;
48
49            long long over_l = l_lim;
50            long long over_r = min(pre_p + (long long)pre_d, cur_p - 1);
51            int overlap = count_walls(walls, over_l, over_r);
52
53            dp[i][0] = max(dp[i][0], dp[i - 1][1] + l_gain - overlap);
54        }
55
56        return max(dp[n - 1][0], dp[n - 1][1]);
57    }
58};