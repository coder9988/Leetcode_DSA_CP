// Last updated: 5/31/2026, 3:21:40 PM
1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int maxSum = INT_MIN;
5        int currSum = 0;
6        for(int i:nums)
7        {
8            currSum += i;
9            maxSum = max(currSum,maxSum);
10            if(currSum<0)
11            {
12                currSum = 0;
13            }
14        }
15        return maxSum;
16    }
17};