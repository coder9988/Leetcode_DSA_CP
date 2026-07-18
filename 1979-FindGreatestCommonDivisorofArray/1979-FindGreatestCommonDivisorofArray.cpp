// Last updated: 7/19/2026, 12:39:25 AM
1class Solution {
2public:
3    int findGCD(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        int small = nums[0];
6        int large = nums[nums.size()-1];
7        while(small>1)
8        {
9            int x = small;
10            small = large%small;
11            large = x;
12        }
13        if(small==1)
14        {
15            return 1;
16        }
17        return large;
18        // 7%3 = 1 so noe large = 3 and small 0 but small became 0 so return large
19    }
20};