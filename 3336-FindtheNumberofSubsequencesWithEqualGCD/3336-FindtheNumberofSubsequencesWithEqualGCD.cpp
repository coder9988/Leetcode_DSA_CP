// Last updated: 7/15/2026, 1:38:47 AM
1class Solution {
2public:
3    int subsequencePairCount(vector<int>& nums) {
4        int mod = 1e9+7;
5        int n = nums.size();
6        int mx = *max_element(nums.begin(), nums.end());
7
8        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1, 0));
9        dp[0][0] = 1;
10
11        for(int num : nums){
12
13            vector<vector<int>> newDp(mx + 1, vector<int>(mx + 1, 0));
14
15            for(int gcd1 = 0; gcd1 <= mx; gcd1++){
16
17                int newGcd1 = gcd(gcd1, num);
18
19                for(int gcd2 = 0; gcd2 <= mx; gcd2++){
20
21                    if(dp[gcd1][gcd2] == 0){
22                        continue;
23                    }
24
25                    int ways = dp[gcd1][gcd2];
26                    int newGcd2 = gcd(gcd2, num);
27
28                    // Ignore current number
29                    newDp[gcd1][gcd2] = (newDp[gcd1][gcd2] + ways) % mod;
30
31                    // Put into first subsequence
32                    newDp[newGcd1][gcd2] = (newDp[newGcd1][gcd2] + ways) % mod;
33
34                    // Put into second subsequence
35                    newDp[gcd1][newGcd2] = (newDp[gcd1][newGcd2] + ways) % mod;
36                }
37            }
38
39            dp = newDp;
40        }
41
42        int ans = 0;
43
44        for(int gcdVal = 1; gcdVal <= mx; gcdVal++){
45            ans = (ans + dp[gcdVal][gcdVal]) % mod;
46        }
47
48        return ans;
49    }
50};