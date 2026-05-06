// Last updated: 5/6/2026, 8:39:49 PM
1class Solution {
2public:
3    static vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
4        const int r=box.size(), c=box[0].size();
5        vector<vector<char>> rotate(c, vector<char>(r, '.'));
6        for(int i=0; i<r; i++){
7            int bottom=c-1;
8            for(int j=c-1; j>=0; j--){
9                if (box[i][j]=='#'){
10                    rotate[bottom][r-1-i]='#';
11                    bottom--;
12                }
13                else if (box[i][j]=='*'){
14                    rotate[j][r-1-i]='*';
15                    bottom=j-1;
16                }
17            }
18        }
19        return rotate;
20    }
21};
22
23
24
25auto init = []()
26{ 
27    ios::sync_with_stdio(0);
28    cin.tie(0);
29    cout.tie(0);
30    return 'c';
31}();