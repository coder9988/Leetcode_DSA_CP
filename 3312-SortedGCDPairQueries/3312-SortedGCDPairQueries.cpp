// Last updated: 7/18/2026, 12:37:45 AM
1class Solution {
2    using ll = long long;
3public:
4    vector<int> gcdValues(vector<int>& A, vector<long long>& queries) {
5        int mx = ranges::max(A);
6        vector<int> freq(mx + 1, 0);
7        vector<ll> GCD(mx + 1, 0);
8        
9        for (auto& a : A) freq[a]++;
10        
11        for (int i = mx; i > 0; i--) {
12            ll sm = 0, extra = 0;
13            for (int j = i; j <= mx; j += i)
14                sm += freq[j], extra += GCD[j];
15            GCD[i] = sm * (sm - 1) / 2 - extra;
16        }
17        
18        partial_sum(GCD.begin(), GCD.end(), GCD.begin());
19        
20        vector<int> res(queries.size());
21        for (int i = 0; i < queries.size(); i++)
22            res[i] = ranges::upper_bound(GCD, queries[i]) - GCD.begin();
23            
24        return res;
25    }
26};