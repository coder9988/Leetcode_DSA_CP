// Last updated: 3/16/2026, 7:52:25 PM
1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& arr) {
4        int start = 0;
5        int end = arr.size()-1;
6        int n = arr.size()-1;
7        if(arr.size()==1)
8        {
9            return arr[0]; 
10        }
11        while(start<=end)
12        {
13            int mid = start + (end-start)/2;
14            if(mid==0 && arr[0]!=arr[1])
15            {
16                return arr[mid];
17            }
18             if(mid==n && arr[n]!=arr[n-1])
19            {
20                return arr[mid];
21            }
22            if(arr[mid-1]!=arr[mid] && arr[mid]!=arr[mid+1])
23            {
24                return arr[mid];
25            }
26            if(mid%2==0)
27            {
28                if(arr[mid]==arr[mid-1])
29                {
30                    end = mid-1;
31                }
32                else
33                {
34                    start = mid+1;
35                }
36            }
37            else
38            {
39                if(arr[mid]==arr[mid-1])
40                {
41                    start = mid+1;
42                }
43                else
44                {
45                    end = mid-1;
46                }
47            }
48        }
49        return -1;
50    }
51};