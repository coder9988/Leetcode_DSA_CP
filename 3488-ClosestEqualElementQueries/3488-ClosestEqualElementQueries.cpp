// Last updated: 4/16/2026, 11:22:45 PM
1#include <memory_resource>
2pmr::unsynchronized_pool_resource pool;
3class Solution {
4public:
5    static vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
6        const int n=nums.size(), qz=queries.size();
7        vector<int> ans(qz, -1);
8        
9        // Store the indices
10        pmr::unordered_map<int, vector<int>> x2i(&pool);
11        x2i.reserve(n);   
12        for (int i=0; i<n; i++) 
13            x2i[nums[i]].push_back(i);
14    
15        // Process each query
16        for (int i=0; i<qz; i++) {
17            const int q=queries[i], x=nums[q];
18            auto& idx=x2i[x];
19            const int sz=idx.size();
20
21            if (sz==1) continue;
22
23            // Find the position of index q 
24            auto i0=lower_bound(idx.begin(), idx.end(), q)-idx.begin();
25
26            int d=n-1, j0=idx[i0];  // Maximum distance
27
28            // Check next index 
29            if (i0+1!=sz) d=min(d, idx[i0+1]-j0);
30            else d=min(d, n+idx[0]-j0);  // Wrap around to the first
31
32            // Check previous index (circularly)
33            if (i0!=0) d=min(d, j0-idx[i0-1]);
34            else d=min(d, n+j0-idx.back());  // Wrap around to the last
35            ans[i]=d;
36        }
37        return ans;
38    }
39};
40