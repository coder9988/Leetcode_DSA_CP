// Last updated: 4/3/2026, 11:04:23 PM
1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int start = 0;
5        int end = nums.size() - 1;
6
7        while(start < end) {
8            int mid = start + (end - start) / 2;
9
10            if(nums[mid] > nums[end]) {
11                start = mid + 1;
12            } else {
13                end = mid;
14            }
15        }
16
17        return nums[start];
18    }
19};