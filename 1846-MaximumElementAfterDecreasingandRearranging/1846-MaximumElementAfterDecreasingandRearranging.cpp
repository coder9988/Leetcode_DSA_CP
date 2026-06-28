// Last updated: 6/29/2026, 12:21:25 AM
1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4
5        sort(arr.begin(), arr.end());
6
7        arr[0] = 1;
8
9        for (int i = 1; i < arr.size(); i++) {
10
11            arr[i] = min(arr[i], arr[i - 1] + 1);
12        }
13
14        return arr.back();
15    }
16};