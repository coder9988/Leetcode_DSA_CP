// Last updated: 7/29/2026, 11:51:12 PM
1class Solution {
2public:
3    long long comb(int n, int r, int lim) {
4        r = min(r, n - r);
5        long long ans = 1;
6        for (int i = 1; i <= r; i++) {
7            ans = ans * (n - r + i) / i;
8            if (ans > lim) return lim + 1;
9        }
10        return ans;
11    }
12
13    long long calc(vector<int> &cnt, int rem, int lim) {
14        long long ans = 1;
15        for (int x : cnt) {
16            if (!x) continue;
17            ans *= comb(rem, x, lim);
18            if (ans > lim) return lim + 1;
19            rem -= x;
20        }
21        return ans;
22    }
23
24    string smallestPalindrome(string s, int k) {
25        vector<int> cnt(26);
26        for (char c : s) cnt[c - 'a']++;
27
28        int n = s.size(), m = n / 2;
29        string ans(n, ' ');
30
31        for (int i = 0; i < 26; i++) {
32            if (cnt[i] & 1) ans[m] = 'a' + i;
33            cnt[i] /= 2;
34        }
35
36        if (calc(cnt, m, k) < k) return "";
37
38        for (int i = 0; i < m; i++) {
39            for (int c = 0; c < 26; c++) {
40                if (!cnt[c]) continue;
41
42                cnt[c]--;
43                long long cur = calc(cnt, m - i - 1, k);
44
45                if (cur >= k) {
46                    ans[i] = 'a' + c;
47                    break;
48                }
49
50                k -= cur;
51                cnt[c]++;
52            }
53        }
54
55        for (int i = 0; i < m; i++)
56            ans[n - 1 - i] = ans[i];
57
58        return ans;
59    }
60};