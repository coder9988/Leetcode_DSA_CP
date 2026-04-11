// Last updated: 4/11/2026, 10:03:39 PM
1const int N=1e5+1;
2int pos[N][2]={[0 ... N-1][0 ... 1]=-1};
3class Solution {
4public:
5    static int minimumDistance(vector<int>& nums) {
6        const int n=nums.size();
7        int ans=INT_MAX, M=0;
8        for(int k=0; k<n; k++){
9            const int x=nums[k];
10            M=max(M, x);
11            if (pos[x][1]!=-1){
12                ans=min(ans, (k-pos[x][1])<<1);
13            }
14            pos[x][1]=exchange(pos[x][0], k);
15        }
16        memset(pos, -1, sizeof(int)*2*(M+1));
17        return ans==INT_MAX?-1:ans;
18    }
19};