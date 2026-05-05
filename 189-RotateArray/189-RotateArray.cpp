// Last updated: 5/5/2026, 8:50:43 PM
1class Solution {
2public:
3void rotate(vector<int>& nums, int k) {
4    int n = nums.size();
5    k = k % n;
6    reverse(nums.begin(), nums.end());
7    reverse(nums.begin(), nums.begin() + k);
8    reverse(nums.begin() + k, nums.end());
9}
10};