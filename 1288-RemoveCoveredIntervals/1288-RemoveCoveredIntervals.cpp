// Last updated: 7/7/2026, 12:46:15 AM
1//translated using AI
2class Solution {
3public:
4    int removeCoveredIntervals(vector<vector<int>>& intervals) {
5        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
6            if (a[0] == b[0])
7                return a[1] > b[1];
8            return a[0] < b[0];
9        });
10
11        int count = 0, maxEnd = 0;
12
13        for (auto& interval : intervals) {
14            if (interval[1] > maxEnd) {
15                count++;
16                maxEnd = interval[1];
17            }
18        }
19
20        return count;
21    }
22};