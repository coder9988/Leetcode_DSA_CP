// Last updated: 5/7/2026, 10:32:13 PM
1class Solution {
2public:
3    vector<int> maxValue(vector<int>& nums) {
4        int n = nums.size();
5
6        vector<int> pre(n), suf(n), res(n);
7        pre[0] = nums[0];
8        for (int i = 1; i < n; i++) {
9            pre[i] = max(pre[i - 1], nums[i]);
10        }
11        suf[n - 1] = nums[n - 1];
12        for (int i = n - 2; i >= 0; i--) {
13            suf[i] = min(suf[i + 1], nums[i]);
14        }
15        res[n - 1] = pre[n - 1];
16        for (int i = n - 2; i >= 0; i--) {
17            if (pre[i] > suf[i + 1]) {
18                res[i] = res[i + 1];
19            }
20            else {
21                res[i] = pre[i];
22            }
23        }
24
25        return res;
26    }
27};