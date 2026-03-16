// Last updated: 3/16/2026, 6:13:04 PM
1unsigned diag[100][51], antid[100][51]; 
2const int OFFSET=50;
3
4class Solution {
5public:
6    static inline int rhombusSum(int i, int j, int d, vector<vector<int>>& grid) {
7        if (d==0) return grid[i][j];
8        
9        const int l=j-d, r=j+d, u=i-d, b=i+d ;
10        
11        // Diagonals with corner (\) 
12        const int i0=u-j+OFFSET, i1=i-l+OFFSET;
13        int sum=diag[i0][r+1]-diag[i0][j];
14        sum+=diag[i1][j+1]-diag[i1][l];
15        
16        // Anti-diagonals without corners (/) 
17        const int j0=u+j, j1=b+j;
18        sum+=antid[j0][i]-antid[j0][u+1];
19        sum+=antid[j1][b]-antid[j1][i+1];
20
21        return sum;
22    }
23
24    static vector<int> getBiggestThree(vector<vector<int>>& grid) {
25        const int m=grid.size(), n=grid[0].size();
26    //  no need for reset    
27    //    memset(diag, 0, sizeof(diag));
28    //    memset(antid, 0, sizeof(antid));
29
30        for (int i=0; i< m; i++) {
31            for (int j = 0; j < n; j++) {
32                const int i0=i-j+OFFSET, j0=i+j;
33                const int x=grid[i][j];
34                // diag over j, antid over i
35                diag[i0][j+1]=diag[i0][j]+x;
36                antid[j0][i+1]=antid[j0][i]+x;
37            }
38        }
39
40        int dM=min(m, n)/2; 
41        vector<int> x(3, -1);
42        for (int d=0; d<=dM; d++) {
43            for (int i=d; i<m-d; i++) {
44                for (int j=d; j<n-d; j++) {
45                    const int y=rhombusSum(i, j, d, grid);
46
47                    // Skip if y is already in our top 3 
48                    if (y==x[0] || y==x[1] || y==x[2]) continue;
49
50                    if (y>x[0]) {
51                        x[2]=x[1]; x[1]=exchange(x[0], y);
52                    }
53                    else if (y>x[1]) x[2]=exchange(x[1], y);
54                    else if (y>x[2]) x[2]=y;
55                }
56            }
57        }
58        for(int i=2; i>=0; i--) 
59            if (x[i]==-1) x.pop_back();
60        return x;
61    }
62};