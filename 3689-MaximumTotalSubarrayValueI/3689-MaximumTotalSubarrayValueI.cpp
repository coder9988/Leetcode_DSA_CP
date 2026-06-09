// Last updated: 6/10/2026, 1:41:25 AM
1class Solution {
2public:
3    long long maxTotalValue(vector<int>& A, int k) {
4        int gMin = A.front(), gMax = A.front();
5
6        for (auto& n : A) {
7            gMin = min(gMin, n);
8            gMax = max(gMax, n);
9        }
10        
11        return (long long)(gMax - gMin) * k;
12    }
13};