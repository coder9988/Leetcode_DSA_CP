// Last updated: 6/21/2026, 1:17:38 AM
1using int2=pair<int, int>;
2const int N=1e5+2;
3static int2 R[N];
4static constexpr int M=1<<10, mask=M-1, bshift=10;
5int freq[M];
6
7void radix_sort(int2* nums, int n) {
8    int2* buffer=(int2*)alloca(n*sizeof(int2));  // buffer
9    int2* in=nums;
10    int2* out=buffer;
11
12    // 3 rounds covers 30 bits 
13    for (int round=0; round < 3; round++) {
14        const int shift=round * bshift;
15        memset(freq, 0, sizeof(freq));
16
17        for (int i=0; i<n; i++)
18            freq[(in[i].first >> shift) & mask]++;
19
20        partial_sum(freq, freq+M, freq);
21
22        for (int i = n - 1; i >= 0; i--) {
23            int x = (in[i].first >> shift) & mask;
24            out[--freq[x]] = in[i];
25        }
26
27        // Swap pointers for the next round
28        swap(in, out);
29    }
30    //data is currently in buffer. We must copy it back to nums.
31    if (in != nums) {
32        memcpy(nums, in, n * sizeof(int2));
33    }
34}
35class Solution {
36public:
37    static int maxBuilding(int n, vector<vector<int>>& restrictions) {
38        int m=restrictions.size();
39        for(int i=0; i<m; i++)
40            R[i]={restrictions[i][0], restrictions[i][1]};
41        R[m]={1, 0};
42        R[m+1]={n, n-1};
43        m+=2;
44        radix_sort(R, m);
45              
46        for(int i=1; i<m; i++)
47            R[i].second=min(R[i].second, R[i-1].second-R[i-1].first+R[i].first);
48        
49        for(int i=m-2; i>=1; i--)
50            R[i].second=min(R[i].second, R[i+1].second+R[i+1].first-R[i].first); 
51
52        int ans=0;
53        for(int i=0; i<m-1; i++){ 
54            int peak=(R[i].second+R[i+1].second+R[i+1].first-R[i].first)/2;
55            ans=max(ans, peak);
56        }
57        return ans;
58    }
59};
60auto init = []() {
61    ios::sync_with_stdio(false);
62    cin.tie(nullptr);
63    cout.tie(nullptr);
64    return 'c';
65}();