// Last updated: 3/27/2026, 10:31:49 PM
1class Solution {
2public:
3    static bool areSimilar(vector<vector<int>>& mat, int k) {
4        const int r=mat.size(),  c=mat[0].size();
5        k%=c;
6        if (k==0) return 1;
7        for(int i=0; i<r; i++){
8            bool iEven=(i&1)==0;
9            for(int j=0; j<c; j++)
10                if(mat[i][j]!=mat[i][(j+(iEven?c-k:k))%c]) return 0;
11        }
12        return 1;
13    }
14};