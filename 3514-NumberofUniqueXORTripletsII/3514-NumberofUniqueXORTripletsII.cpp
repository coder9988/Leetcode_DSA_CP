// Last updated: 7/25/2026, 12:28:42 AM
1const int N=1<<11;
2uint8_t seen3[N];
3uint64_t seen2[32];
4class Solution {
5public:
6    static int uniqueXorTriplets(vector<int>& nums) {
7        const int n=nums.size();
8        if (n==1) return 1;
9        unsigned M=*max_element(nums.begin(), nums.end());
10        M=(bit_floor(M)<<1)-1;
11        memset(seen3, 0, M+1);
12        int qM=M>>6;
13        memset(seen2, 0, (qM+1)*sizeof(uint64_t));
14        int cnt=0;
15        for(int i=0; i<n; i++){
16            const int x=nums[i];
17            
18            cnt+=(!seen3[x]);
19            seen3[x]=1;
20
21            for(int j=i+1; j<n; j++){
22                const int y=x^nums[j];
23                const int q=y>>6, r=y&63;
24                seen2[q]|=(1ULL<<r);
25            }
26      
27            for(int q=0; q<=qM; q++){
28                uint64_t B=seen2[q];
29                for( ; B; B&=(B-1)){
30                    const int r=__builtin_ctzll(B);
31                    const int y=(q<<6)+r;
32                
33                    cnt+=(!seen3[x^y]);
34                    seen3[x^y]=1;
35                }
36            }
37        }
38        return cnt;
39    }
40};
41
42
43auto init = []() {
44    ios::sync_with_stdio(false);
45    cin.tie(nullptr);
46    cout.tie(nullptr);
47    return 'c';
48}();