// Last updated: 7/17/2026, 1:30:05 AM
1class Solution {
2public:
3    long long gcdSum(vector<int>& A) {
4        int max = 0;
5
6        for (auto& n : A) {
7            max = ::max(max, n);
8            n = gcd(n, max);
9        }
10
11        ranges::sort(A);
12
13        long long res = 0;
14        for (int i = 0, j = A.size() - 1; i < j; i++, j--)
15            res += gcd(A[i], A[j]);
16
17        return res;
18    }
19};