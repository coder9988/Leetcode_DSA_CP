// Last updated: 6/9/2026, 12:27:19 AM
1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        int n=nums.size();
5        if (n==1) return nums;
6        vector<int> R;
7        int l=0, m=0, sz=n;
8        for(int x: nums){
9            if (x<pivot) nums[l++]=x;
10            else if (x>pivot) R.push_back(x), sz--;
11            else m++;
12        }
13        auto it_m=nums.begin()+l;
14        fill(it_m, it_m+m, pivot);
15        copy(R.begin(), R.end(), it_m+m);
16        return nums;
17    }
18};