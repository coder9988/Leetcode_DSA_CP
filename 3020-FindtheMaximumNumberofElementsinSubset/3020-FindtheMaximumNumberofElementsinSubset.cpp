// Last updated: 6/28/2026, 1:14:08 AM
1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        unordered_map<long long, int> mp;
5
6        for (int x : nums)
7            mp[x]++;
8
9        int ans = 1;
10
11        // Handle 1 separately
12        if (mp.count(1)) {
13            int cnt = mp[1];
14            ans = max(ans, cnt % 2 ? cnt : cnt - 1);
15        }
16
17        for (auto &[num, f] : mp) {
18            if (num == 1) continue;
19
20            long long x = num;
21            int len = 0;
22
23            while (mp.count(x) && mp[x] >= 2) {
24                len += 2;
25
26                if (x > 1e9) break; // avoid overflow
27                x = x * x;
28            }
29
30            if (mp.count(x))
31                len++;
32
33            else
34                len--;
35
36            ans = max(ans, len);
37        }
38
39        return ans;
40    }
41};