// Last updated: 6/22/2026, 1:50:38 AM
1constexpr int M = 1e5 + 1;
2int freq[M];
3class Solution {
4public:
5    static int maxIceCream(vector<int>& costs, int coins) {
6        int xMax = 0;
7        for (int x : costs) {
8            freq[x]++;
9            xMax = max(xMax, x);
10        }
11        int cnt = 0;
12        for (int x = 1; x <= xMax; x++) {
13            const int f = freq[x];
14            if (f == 0)
15                continue;
16            int buy = min(coins / x, f);
17            if (buy == 0)
18                break;
19            cnt += buy;
20            coins -= buy * x;
21        }
22        // reset for the next testcase
23        for (int x : costs)
24            freq[x] = 0;
25        return cnt;
26    }
27};
28auto init = []() {
29    ios::sync_with_stdio(false);
30    cin.tie(nullptr);
31    cout.tie(nullptr);
32    return 'c';
33}();