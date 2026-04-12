// Last updated: 4/12/2026, 8:45:43 PM
1int dp[300][27];
2class Solution {
3public:
4    static inline int dist(int x, int y) {
5        if (x==26 || y==26) return 0; // 26 denotes hovering 
6        return abs(x/6-y/6)+abs(x%6-y%6);
7    }
8
9    static int minimumDistance(string& word) {
10        const int n=word.size();
11        constexpr int INF=1e9+7;
12        fill(&dp[0][0], &dp[0][0]+n*27, INF);// reset 
13        dp[0][26]=0;
14        int prev=word[0]-'A'; 
15
16        for (int i=1; i<n; i++) {
17            int x=word[i]-'A';
18
19            for (int j=0; j<27; j++) {
20                if (dp[i-1][j]>=INF) continue;
21
22                // Move the current finger
23                dp[i][j]=min(dp[i][j], dp[i-1][j] + dist(prev, x));
24
25                // Move the other finger 
26                dp[i][prev]=min(dp[i][prev], dp[i-1][j]+dist(j, x));
27            }
28            prev=x; // Update prev to x
29        }
30
31        return *min_element(dp[n-1], dp[n-1]+27);
32    }
33};