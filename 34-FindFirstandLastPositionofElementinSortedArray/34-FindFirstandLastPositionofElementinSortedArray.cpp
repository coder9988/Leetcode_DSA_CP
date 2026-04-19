// Last updated: 4/19/2026, 2:11:56 PM
1class Solution {
2public:
3    int findFirst(vector<int>& nums, int target) {
4        int start = 0, end = nums.size() - 1;
5        int ans = -1;
6
7        while (start <= end) {
8            int mid = start + (end - start) / 2;
9
10            if (nums[mid] == target) {
11                ans = mid;
12                end = mid - 1;
13            }
14            else if (nums[mid] < target) {
15                start = mid + 1;
16            }
17            else {
18                end = mid - 1;
19            }
20        }
21        return ans;
22    }
23
24    int findLast(vector<int>& nums, int target) {
25        int start = 0, end = nums.size() - 1;
26        int ans = -1;
27
28        while (start <= end) {
29            int mid = start + (end - start) / 2;
30
31            if (nums[mid] == target) {
32                ans = mid;
33                start = mid + 1;
34            }
35            else if (nums[mid] < target) {
36                start = mid + 1;
37            }
38            else {
39                end = mid - 1;
40            }
41        }
42        return ans;
43    }
44
45    vector<int> searchRange(vector<int>& nums, int target) {
46        return {findFirst(nums, target), findLast(nums, target)};
47    }
48};