// Last updated: 2/28/2026, 8:00:03 PM
1class Solution {
2public:
3    static int concatenatedBinary(int n) {
4        constexpr int mod=1e9+7;
5        uint64_t ans=0;
6        for(unsigned x=1; x<=n; x++){
7            const int bw=32-countl_zero(x);
8            ans=(ans<<bw)+x;
9            if (ans>=mod) ans%=mod;
10        }
11        return ans;
12    }
13};