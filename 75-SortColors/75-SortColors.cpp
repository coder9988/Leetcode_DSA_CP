// Last updated: 4/11/2026, 11:21:58 PM
1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        for (int i = 0; i < nums.size(); i++) {
5            for (int j = 0; j < nums.size(); j++) {
6                if (nums[i] < nums[j]) {
7                    swap(nums[i], nums[j]);
8                }
9            }
10        }
11    }
12};