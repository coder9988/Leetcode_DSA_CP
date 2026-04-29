// Last updated: 4/29/2026, 8:47:07 PM
1using ll=long long;
2static ll colSum[100][101]={{0}}; // 1-indexed prefix col sums
3// (j, num of black items in curr col, cur col score exclusive/inclusive)
4static ll dp[100][101][2];
5static int n;
6
7class Solution {
8public:
9    static long long maximumScore(vector<vector<int>>& grid) {
10        n=grid.size();
11        if (n==1) return 0;
12        // compute col prefix sums
13        for(int i=0; i<n; i++){
14            for(int j=0; j<n; j++){
15                colSum[j][i+1]=colSum[j][i]+grid[i][j];
16            }
17        }
18        for(int j=0; j<n; j++)
19            memset(dp[j], 0, sizeof(ll)*(n+1)*2);
20
21        for(int j=1; j<n; j++){
22            for(int b0=0; b0<=n; b0++){
23                ll p0=dp[j-1][b0][0];
24                ll p1=dp[j-1][b0][1];
25
26                for(int b1=0; b1<=n; b1++){
27                    bool isBigger=b1>b0;
28                    
29                    ll prvX=isBigger?(colSum[j-1][b1]-colSum[j-1][b0]):0;
30                    ll curX=!isBigger?(colSum[j][b0]-colSum[j][b1]):0;
31                    
32                    // State 0: score in cur col exclusive
33                    dp[j][b1][0]=max(dp[j][b1][0], max(prvX+p0, p1));
34                    
35                    // State 1: score in cur col inclusive
36                    dp[j][b1][1]=max(dp[j][b1][1], curX+max(p1, prvX+p0));
37                }
38            }
39        }
40        ll ans=0;
41        for(int b=0; b<=n; b++) 
42            ans=max(ans, dp[n-1][b][1]);
43        
44        return ans;
45    }
46};
47
48auto init = []() {
49    ios::sync_with_stdio(0);
50    cin.tie(0);
51    cout.tie(0);
52    return 'c';
53}();