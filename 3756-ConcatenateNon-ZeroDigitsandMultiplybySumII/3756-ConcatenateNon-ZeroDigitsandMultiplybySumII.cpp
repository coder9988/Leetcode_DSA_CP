// Last updated: 7/9/2026, 12:32:26 AM
1class Solution {
2private:
3    static constexpr int MOD = 1000000007;
4    static constexpr int MAX = 100001;
5    inline static int pow[MAX];
6
7    inline static int init = []() {
8        pow[0] = 1;
9        for (int i = 1; i < MAX; i++)
10            pow[i] = pow[i - 1] * 10LL % MOD;
11        return 0;
12    }();
13
14public:
15    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
16        int n = s.length();
17        
18        vector<int> A(n + 1, 0);
19        vector<int> B(n + 1, 0);
20        vector<int> len(n + 1, 0);
21
22        for (int i = 0; i < n; i++) {
23            int d = s[i] - '0';            
24            A[i + 1] = A[i] + d;
25            
26            if (d) {
27                B[i + 1] = (B[i] * 10LL + d) % MOD;
28                len[i + 1] = len[i] + 1;
29            } else {
30                B[i + 1] = B[i];
31                len[i + 1] = len[i];
32            }
33        }
34
35        vector<int> res;
36        res.reserve(queries.size());
37
38        for (auto& q : queries) {
39            int l = q[0], r = q[1] + 1;
40
41            long long sub = B[l] * 1LL * pow[len[r] - len[l]] % MOD;
42            long long x = (B[r] - sub + MOD) % MOD;
43
44            res.push_back(x * (A[r] - A[l]) % MOD);
45        }
46
47        return res;
48    }
49};