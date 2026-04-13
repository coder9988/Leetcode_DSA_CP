// Last updated: 4/13/2026, 9:17:20 PM
1class Solution {
2public:
3    int getMinDistance(vector<int>& nums, int target, int start) {
4        int result = nums.size();
5        for(int i=0;i<nums.size();i++){
6            if(nums[i]==target)
7                result = min(result,abs(i-start));
8        }
9        return result;
10    }
11};