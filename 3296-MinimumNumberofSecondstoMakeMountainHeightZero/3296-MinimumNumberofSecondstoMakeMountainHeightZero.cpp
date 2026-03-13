// Last updated: 3/13/2026, 8:03:41 PM
1using ll = long long;
2class Solution {
3public:
4    ll minNumberOfSeconds(int height, vector<int>& times) {
5        ll lo = 1, hi = 1e16;
6
7        while (lo < hi) {
8            ll mid = (lo + hi) >> 1;
9            ll tot = 0;
10            for (int i = 0; i < times.size() && tot < height; i++)
11                tot += (ll)(sqrt((double)mid / times[i] * 2 + 0.25) - 0.5);
12            if (tot >= height)
13                hi = mid;
14            else
15                lo = mid + 1;
16        }
17
18        return lo;
19    }
20};