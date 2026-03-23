// Last updated: 3/23/2026, 11:43:06 PM
1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int sum = 0;
5        int maxSum = INT_MIN;
6        for(int i = 0;i<nums.size();i++)
7        {
8            sum += nums[i];
9            if(sum>maxSum)
10            {
11                maxSum = sum;
12            }
13            if(sum<0)
14            {
15                sum = 0;
16            }
17        }
18        return maxSum;
19    }
20};