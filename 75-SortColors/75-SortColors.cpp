// Last updated: 4/16/2026, 4:04:03 PM
1class Solution {
2public:
3    void sortColors(vector<int>& nums) {
4        int low = 0;
5        int mid = 0;
6        int high = nums.size()-1;
7     while(mid<=high)
8     {
9        if(nums[mid]==0)
10        {
11            swap(nums[low],nums[mid]);
12            mid++;
13            low++;
14        }
15       else if(nums[mid]==1)
16        {
17            mid++;
18        }
19        else
20        {
21             swap(nums[mid], nums[high]);
22            high--;
23        }
24     }
25
26    }
27};