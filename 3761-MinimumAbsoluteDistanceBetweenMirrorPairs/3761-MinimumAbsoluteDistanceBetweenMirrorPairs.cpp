// Last updated: 4/17/2026, 11:14:40 PM
1class Solution {
2public:
3    int reverse(int x) {
4        int rev = 0;
5        while (x > 0) {
6            rev = rev * 10 + x % 10;
7            x /= 10;
8        }
9        return rev;
10    }
11
12    int minMirrorPairDistance(vector<int>& a) {
13        unordered_map<int, int> mpp;
14        int n = a.size(), ans = 1e6;
15
16        for (int i = 0; i < n; i++) {
17            if (mpp.count(a[i])) {
18                ans = min(ans, i - mpp[a[i]]);
19            }
20            mpp[reverse(a[i])] = i;
21        }
22        return ans == 1e6 ? -1 : ans;
23    }
24};