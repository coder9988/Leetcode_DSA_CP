// Last updated: 4/9/2026, 8:07:45 PM
1class Solution {
2public:
3    const int mod = 1e9 + 7;
4    long long power(long long base, long long exp){
5        long long res = 1;
6        while(exp > 0){
7            if(exp & 1) res = (res * base) % mod;
8            base = (base * base) % mod;
9            exp >>= 1;
10        }
11        return res;
12    }
13
14    long long modInv(long long n){
15        return power(n, mod - 2);
16    }
17
18    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
19        int n = nums.size();
20        int limit = sqrt(n);
21        
22        // group queries with small k for later processing
23        unordered_map<int, vector<vector<int>>> lightK;
24
25        for(auto& q : queries){
26            int l = q[0], r = q[1], k = q[2], v = q[3];
27            if(k >= limit){ // large k: apply brute force
28                for(int i = l; i <= r; i += k)
29                    nums[i] = (1LL * nums[i] * v) % mod;
30            } else { // small k: process later
31                lightK[k].push_back(q);
32            } 
33        }
34
35        for(auto& [k, query] : lightK){
36            // process small queries grouped by step size k
37            vector<long long> diff(n, 1);
38            for(auto& q : query){
39                int l = q[0], r = q[1], v = q[3];
40                // multiply starting position
41                diff[l] = (diff[l] * v) % mod;
42                // cancel the multiplication using modular inverse
43                int steps = (r - l) / k;
44                int next = l + (steps + 1) * k;
45                if(next < n){
46                    diff[next] = (diff[next] * modInv(v)) % mod;
47                }
48            }
49            
50            // propagate the multipliers with a step size of k
51            for(int i = 0; i < n; i++){
52                if(i >= k) diff[i] = (diff[i] * diff[i-k]) % mod;
53                nums[i] = (1LL * nums[i] * diff[i]) % mod;
54            }
55        }
56
57        int ans = 0;
58        for(auto& num : nums) ans ^= num;
59
60        return ans;    
61    }
62};