# Last updated: 7/26/2026, 11:43:50 PM
1class Solution:
2    def maximumProduct(self, A: list[int]) -> int:
3        n = len(A)
4
5        for i in range(2):
6            k = i
7            for j in range(i + 1, n):
8                if A[j] < A[k]:
9                    k = j
10            A[i], A[k] = A[k], A[i]
11
12        for i in range(n - 1, max(-1, n - 4), -1):
13            k = i
14            for j in range(i):
15                if A[j] > A[k]:
16                    k = j
17            A[i], A[k] = A[k], A[i]
18
19        return max(
20            A[-1] * A[-2] * A[-3],
21            A[-1] * A[0] * A[1]
22        )