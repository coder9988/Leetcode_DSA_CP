// Last updated: 3/16/2026, 5:17:46 PM
1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        int start = 0;
5        int end = nums.size() - 1;
6        while (start <= end) {
7            int mid = start + (end - start) / 2;
8            if(target == nums[mid]) return mid;
9            if (nums[start] <= nums[mid]) {
10                if (nums[start] <= target && target <= nums[mid]) {
11                    end = mid - 1;
12                } else {
13                    start = mid + 1;
14                }
15            } else if (nums[mid] <= nums[end]) {
16                if (nums[mid] <= target && target <= nums[end]) {
17                    start = mid + 1;
18                } else {
19                    end = mid - 1;
20                }
21            }
22        }
23        return -1;
24    }
25};