// Last updated: 3/22/2026, 6:47:40 PM
1class Solution {
2public:
3    void rotate(vector<vector<int>>& mat) {
4        int n = mat.size();
5        for (int i = 0; i < n; i++) {
6            for (int j = i + 1; j < n; j++) {
7                swap(mat[i][j], mat[j][i]);
8            }
9        }
10        for (int i = 0; i < n; i++) {
11            reverse(mat[i].begin(), mat[i].end());
12        }
13    }
14    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
15        for (int i = 0; i < 4; i++) {
16            if (mat == target) return true;
17            rotate(mat);
18        }
19        return false;
20    }
21};