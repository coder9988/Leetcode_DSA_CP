// Last updated: 7/11/2026, 1:21:28 AM
1constexpr int L=18, N=1e5+1;
2using int2=pair<int, int>;
3int up[L][N], pos[N]; 
4int2 xId[N];
5
6class Solution {
7public:
8    static int cnt(int u, int v, int L) {
9        if (u==v) return 0;
10        if (up[0][u]>=v) return 1;
11        // cannot reach v
12        if (up[L-1][u]<v) return -1; 
13
14        int step=0;
15        for (int j=L-1; j>=0; j--) { 
16            if (up[j][u]<v) { // Only jump when satisfied
17                step+=(1<<j);
18                u=up[j][u];
19            }
20        }
21        return step+1;
22    }
23
24    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
25        int maxL=bit_width((unsigned)n)+1;
26        for(int i=0; i<n; i++) 
27            xId[i]={nums[i], i};
28        
29        sort(xId, xId+n);
30        for (int i=0; i<n; i++)// pos of index in sorted xId
31            pos[xId[i].second]=i;
32        
33        //sliding window 
34        for (int l=0, r=0; l<n; l++) {
35            while (r+1<n && xId[r+1].first-xId[l].first<=maxDiff) 
36                r++;
37            up[0][l]=r;
38        }
39
40        // Compute binary lifting tables
41        for (int j=1; j<maxL; j++) {
42            for (int i=0; i<n; i++) {
43                up[j][i]=up[j-1][up[j-1][i]];
44            }
45        }
46
47        const int qz=queries.size();
48        vector<int> ans(qz);
49        int i=0;
50        for (auto& q : queries) {
51            auto [u, v]=minmax(pos[q[0]], pos[q[1]]);
52            ans[i++]=cnt(u, v, maxL);
53        }
54        return ans;
55    }
56};