// Last updated: 5/15/2026, 12:03:54 AM
1class Solution {
2public:
3    bool isGood(vector<int>& nums) {
4        const int n=nums.size()-1;
5        if (n==0) return 0;
6        int freq[201]={0};
7        for(int x : nums){
8            if (++freq[x]==2){
9                if (x!=n) return 0;
10            }
11        }
12        for(int x=1; x<=n-1; x++){
13            if (freq[x]!=1) return 0;
14        }
15        return freq[n]==2;
16    }
17};