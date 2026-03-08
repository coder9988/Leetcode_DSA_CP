// Last updated: 3/8/2026, 11:27:01 PM
1class Solution {
2public:
3    string findDifferentBinaryString(vector<string>& nums) {
4        const int len=nums[0].size();
5        vector<bool> hasX(1<<len, 0);
6        for(auto& x:  nums)
7            hasX[bitset<16>(x).to_ulong()]=1;
8        int N=0;//find N
9
10        for(; N<(1<<len) && hasX[N]; N++);
11    //    cout<<N<<endl;
12        return bitset<16>(N).to_string().substr(16-len,len);
13    }
14};