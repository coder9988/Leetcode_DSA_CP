// Last updated: 5/31/2026, 3:22:17 PM
1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int sum = INT_MIN;
5        int currsum = 0;
6        for(int i=0;i<nums.size();i++)
7        {
8            currsum += nums[i];
9            sum = max(sum,currsum);
10            if(currsum<0)
11            {
12                currsum = 0;
13            }
14           
15        }
16        return sum;
17    }
18};