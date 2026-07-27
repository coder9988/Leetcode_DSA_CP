// Last updated: 7/28/2026, 12:27:38 AM
1#pragma GCC optimize("O3", "unroll-loops")
2class Solution {
3public:
4    int maxProduct(vector<int>& nums) {
5        int n=nums.size();
6        if (n<3) return (nums[0]-1)*(nums.back()-1);
7        int m0=nums[0],m1=nums[1];
8        if(m0<m1) swap(m0,m1);
9        for (int i=2;i<n;i++){
10            int x=nums[i];
11            if(x>m0){
12                m1=m0, m0=x;
13            }
14            else if(x>m1) m1=x;
15        }
16        return (m0-1)*(m1-1);
17    }
18};
19auto init = []()
20{ 
21    ios::sync_with_stdio(0);
22    cin.tie(0);
23    cout.tie(0);
24    return 'c';
25}();