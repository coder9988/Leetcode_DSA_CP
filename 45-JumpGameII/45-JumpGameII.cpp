// Last updated: 4/25/2026, 6:17:16 PM
1class Solution {
2public:
3
4    int jump(vector<int>& nums) {
5        int j = 0;
6        int l = 0;
7        int r = 0;
8        int n = nums.size()-1;
9        int further;
10        while(r<n)
11        {
12            further = 0;
13            for(int i = l;i<=r;i++)
14            {
15                further = max(further,i+nums[i]);
16            }
17            j += 1;
18            l = r+1;
19            r = further;
20        }
21        return j;
22    }
23};