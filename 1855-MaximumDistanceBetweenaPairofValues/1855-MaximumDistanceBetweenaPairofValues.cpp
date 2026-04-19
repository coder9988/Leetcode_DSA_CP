// Last updated: 4/19/2026, 1:33:42 PM
1class Solution {
2public:
3    int maxDistance(vector<int>& A, vector<int>& B) {
4        int i, j;
5
6        for (i = 0, j = 0; i < A.size() && j < B.size(); j++)
7            i += A[i] > B[j];
8
9        return max(0, j - i - 1);
10    }
11};