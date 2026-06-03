// Last updated: 6/4/2026, 12:43:32 AM
1class Solution {
2    static inline int MAX = 300005;
3public:
4    int earliestFinishTime(vector<int>& la, vector<int>& lb, vector<int>& wa, vector<int>& wb) {
5        int l = MAX, w = MAX, minL = MAX, minW = MAX;
6        int n = la.size(), m = wa.size();
7
8        for (int i = 0; i < n; i++)
9            l = min(l, la[i] + lb[i]);
10
11        for (int i = 0; i < m; i++) {
12            w = min(w, wa[i] + wb[i]);
13            minL = min(minL, max(wa[i], l) + wb[i]);
14        }
15
16        for (int i = 0; i < n; i++)
17            minW = min(minW, max(la[i], w) + lb[i]);
18
19        return min(minW, minL);
20    }
21};