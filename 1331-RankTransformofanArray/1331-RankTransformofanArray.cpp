// Last updated: 7/12/2026, 11:17:31 PM
1class Solution {
2public:
3    vector<int> arrayRankTransform(vector<int>& arr) {
4        vector<int> s = arr;
5        sort(s.begin(), s.end());
6        s.erase(unique(s.begin(), s.end()), s.end());
7        for (int i = 0; i < arr.size(); i++) {
8            arr[i] = lower_bound(s.begin(), s.end(), arr[i]) - s.begin() + 1;
9        }
10        return arr;
11    }
12};