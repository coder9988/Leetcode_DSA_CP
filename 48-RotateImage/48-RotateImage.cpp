// Last updated: 5/4/2026, 7:10:43 PM
1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        int n = matrix.size();
5        for(int i = 0; i < n; i++){
6            for(int j = i + 1; j < n; j++){
7                swap(matrix[i][j], matrix[j][i]);
8            }
9        }
10
11        // Step 2: reverse each row
12        for(int i = 0; i < n; i++){
13            reverse(matrix[i].begin(), matrix[i].end());
14        }
15    }
16};