// Last updated: 6/7/2026, 2:01:46 AM
1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        const int n=nums.size();
5        vector<int> ans(n);
6        int lsum=0, rsum=accumulate(nums.begin(), nums.end(), 0);
7        for(int i=0; i<n; i++){
8            const int x=nums[i];
9            rsum-=x;
10            ans[i]=(rsum>=lsum)?rsum-lsum:lsum-rsum;
11            lsum+=x;
12        }
13        return ans;
14    }
15};