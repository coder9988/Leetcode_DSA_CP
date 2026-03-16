// Last updated: 3/16/2026, 6:12:17 PM
1class Solution {
2public:
3    int peakIndexInMountainArray(vector<int>& arr) {
4        int start = 1;
5        int end = arr.size() - 2;
6        while (start <= end)
7         {
8            int mid = start + (end - start) / 2;
9            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
10            {
11                return mid;
12            }
13            if (arr[mid - 1] < arr[mid]) {
14                start = mid + 1;
15            } else {
16                end = mid - 1;
17            }
18        }
19        return -1;
20    }
21    };